/*
 *  Copyright (C) 2018 Systerel and others.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

MACHINE
    subscription_core_1

SEES
    constants,
    message_out_bs,
    request_handle_bs

DEFINITIONS
    d_variables ==
    s_subscription,
    a_subscription_session,
    a_publishInterval,
    a_lifetimeExpCount,
    a_keepAliveExpCount,
    a_maxNotifsPerPublish,
    a_subscription_state,
    a_MoreNotifications,
    a_LifetimeCounter,
    a_KeepAliveCounter,
    a_MessageSent,
    a_PublishingEnabled,
    a_SeqNum,

    a_pendingNotificationQueue,
    a_publishRequestQueue,
    a_monitoredItemQueue,
    a_publishTimer;
    
    d_typing ==
    s_subscription <: t_subscription &

    /* Subscription configuration record */
    a_subscription_session : s_subscription >+> t_session &                  // a subscription may be associated to a session (=> 1 subscription / session)
    a_publishInterval : s_subscription --> t_opcua_duration_i & // a subscription shall have a publishing interval value
    a_lifetimeExpCount : s_subscription --> t_counter &       // a subscription shall have a lifetime expiration count value
    a_keepAliveExpCount : s_subscription --> t_counter &      // a subscription shall have a keepAlive expiration count value
    a_maxNotifsPerPublish : s_subscription --> t_counter &    // a subscription shall have a maximum notifications per publish response
    
    /* Subscription State Machine : state shall be defined (part 4 table 82) */
    a_subscription_state : s_subscription --> t_subscriptionState &
    
    /* Subscription State Machine : variables shall be defined (part 4 table 84) */
    a_MoreNotifications <: s_subscription &
    a_LifetimeCounter : s_subscription --> t_counter &
    a_KeepAliveCounter : s_subscription --> t_counter & /* missing in table 84 */
    a_MessageSent <: s_subscription &
    /* a_NotificationAvailable <: s_subscription & */ /* <=> a_monitored_item_notifications[{queue}] /= {} */
    a_PublishingEnabled <: s_subscription &
    /* a_PublishingReqQueued <: s_subscription & */ /* <=> a_publish_responses~[{queue}] /= {} */
    /* a_RequestedMessageFound <: s_subscription */   /* <=> seqNum in a_retransmissionQueue[subscription] */
    a_SeqNum : s_subscription --> t_sub_seq_num &
    /* a_SubscriptionAssignedToClient <: s_subscription */             /* Not really a state machine variable: local variable or function */
    
    /* Subscription Implementation variables */    
    a_pendingNotificationQueue : s_subscription --> t_notificationQueue &
    /* a_retransmissionQueue : s_subscription --> t_notificationMsgQueue */ /* not implemented */
    a_monitoredItemQueue : s_subscription --> t_monitoredItemQueue &
    
    a_publishTimer : s_subscription --> t_timer_id &
    
    /* (Session) Implementation variables */
    
    /* Note: kept on subscription for now since 1 subs / session + no transfer. Otherwise could be cleared on session close ! */
    a_publishRequestQueue :  s_subscription --> t_publishReqQueue
    
ABSTRACT_VARIABLES
    d_variables

INVARIANT
    d_typing

INITIALISATION
    s_subscription := {}             ||
    a_subscription_session := {}     ||
    a_publishInterval := {}          ||
    a_lifetimeExpCount := {}         ||
    a_keepAliveExpCount := {}        ||
    a_maxNotifsPerPublish := {}      ||

    a_subscription_state := {}       ||

    a_MoreNotifications := {}        ||
    a_LifetimeCounter := {}          ||
    a_KeepAliveCounter := {}         ||
    a_MessageSent := {}              ||
    a_PublishingEnabled := {}        ||
    a_SeqNum := {}                   ||

    a_pendingNotificationQueue := {} ||
    a_publishRequestQueue := {}      ||
    a_monitoredItemQueue := {} ||
    a_publishTimer := {}

OPERATIONS
    
    is_valid <-- is_valid_subscription (p_subscription) =
    PRE
        p_subscription : t_subscription_i
    THEN
        is_valid := bool(p_subscription : s_subscription)
    END
    ;
    
    p_dom, p_subscription <-- getall_subscription (p_session) =
    PRE
        p_session : t_session_i &
        p_session : t_session &
        p_session : ran(a_subscription_session)
    THEN
        p_dom := bool(p_session : ran(a_subscription_session)) ||
        IF p_session /: ran(a_subscription_session)
        THEN
            p_subscription := c_subscription_indet
        ELSE
            p_subscription := a_subscription_session~(p_session)            
        END
    END
    ;
    
    remove_subscription_session (p_subscription, p_session) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : s_subscription &
        p_session : t_session_i &
        p_session : t_session
    THEN
        a_subscription_session := a_subscription_session - {p_subscription |-> p_session}
    END
    ;
    
    add_subscription (p_subscription,
                      p_session,
                      p_revPublishInterval,
                      p_revLifetimeCount,
                      p_revMaxKeepAlive,
                      p_maxNotificationsPerPublish,
                      p_publishEnabled,
                      p_notifQueue,
                      p_publishQueue,
                      p_monitoredItemQueue,
                      p_timerId) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : t_subscription &
        p_subscription /: s_subscription &
        p_session : t_session_i &
        p_session : t_session &
        p_session /: ran(a_subscription_session) & /* (=> 1 subscription / session) */
        p_revPublishInterval : t_opcua_duration_i &
        p_revLifetimeCount : t_counter &
        p_revLifetimeCount > 0 &
        p_revMaxKeepAlive : t_counter &
        p_revMaxKeepAlive > 0 &
        p_revLifetimeCount >= 3 * p_revMaxKeepAlive & /* part 4 table 86 */
        p_maxNotificationsPerPublish : t_counter &
        p_publishEnabled = TRUE & /* => no subscription modification for now => refuse publishDisabled */
        p_notifQueue : t_notificationQueue_i &
        p_notifQueue : t_notificationQueue &
        p_publishQueue : t_publishReqQueue_i &
        p_publishQueue : t_publishReqQueue &
        p_monitoredItemQueue : t_monitoredItemQueue_i &
        p_monitoredItemQueue : t_monitoredItemQueue &
        p_timerId : t_timer_id_i &
        p_timerId : t_timer_id
    THEN
        s_subscription := s_subscription \/ {p_subscription} ||
        a_subscription_state (p_subscription) := e_subscriptionState_normal   ||
        
        a_subscription_session (p_subscription) := p_session ||
        a_publishInterval (p_subscription) := p_revPublishInterval ||
        a_lifetimeExpCount (p_subscription) := p_revLifetimeCount  ||
        a_LifetimeCounter (p_subscription) := p_revLifetimeCount   ||
        a_keepAliveExpCount (p_subscription) := p_revMaxKeepAlive  ||
        a_KeepAliveCounter (p_subscription) := p_revMaxKeepAlive   ||
        a_maxNotifsPerPublish (p_subscription) := p_maxNotificationsPerPublish ||       
        a_MessageSent := a_MessageSent - {p_subscription}                      ||
        a_PublishingEnabled := a_PublishingEnabled \/ {p_subscription}         ||
        a_SeqNum (p_subscription) := c_sub_seq_num_init                        || /* => next SeqNum == 1 */
        
        a_pendingNotificationQueue (p_subscription) := p_notifQueue ||
        a_publishRequestQueue (p_subscription) := p_publishQueue ||
        a_monitoredItemQueue (p_subscription) := p_monitoredItemQueue ||
        a_publishTimer (p_subscription) := p_timerId
    END
    ;
    
    delete_subscription (p_subscription) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : s_subscription
    THEN
        s_subscription := s_subscription - {p_subscription} ||
        
        a_subscription_session := {p_subscription} <<| a_subscription_session ||
        a_publishInterval := {p_subscription} <<| a_publishInterval ||
        a_lifetimeExpCount := {p_subscription} <<| a_lifetimeExpCount  ||
        a_keepAliveExpCount := {p_subscription} <<| a_keepAliveExpCount ||
        a_maxNotifsPerPublish := {p_subscription} <<| a_maxNotifsPerPublish ||
        
        a_subscription_state := {p_subscription} <<| a_subscription_state ||
        a_LifetimeCounter := {p_subscription} <<| a_LifetimeCounter ||
        a_KeepAliveCounter := {p_subscription} <<| a_KeepAliveCounter ||
        a_MessageSent := a_MessageSent - {p_subscription}               ||
        a_PublishingEnabled := a_PublishingEnabled - {p_subscription}   ||
        a_SeqNum := {p_subscription} <<| a_SeqNum ||
        
        a_pendingNotificationQueue := {p_subscription} <<| a_pendingNotificationQueue ||
          
        a_publishRequestQueue := {p_subscription} <<| a_publishRequestQueue ||

        a_monitoredItemQueue := {p_subscription} <<| a_monitoredItemQueue ||

        a_publishTimer := {p_subscription} <<| a_publishTimer

    END
    ;
    
    p_timer_id <-- get_subscription_timer_id (p_subscription) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : s_subscription
    THEN
        p_timer_id :(p_timer_id : t_timer_id_i &  p_timer_id = a_publishTimer (p_subscription))
    END
    ;
    
    set_subscription_state (p_subscription, p_state) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : dom(a_subscription_state) &
        p_state : t_subscriptionState_i &
        p_state : t_subscriptionState
    THEN
        a_subscription_state (p_subscription) := p_state
    END
    ;
    
    p_state <-- get_subscription_state (p_subscription) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : dom(a_subscription_state)
    THEN
        p_state := a_subscription_state (p_subscription)
    END
    ;
    
    set_subscription_MoreNotifications (p_subscription, p_moreNotifs) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : s_subscription &
        p_moreNotifs : BOOL
    THEN
        IF p_moreNotifs = TRUE
        THEN
            a_MoreNotifications := a_MoreNotifications \/ {p_subscription}
        ELSE
            a_MoreNotifications := a_MoreNotifications - {p_subscription}
        END
    END
    ;
    
    p_moreNotifs <-- get_subscription_MoreNotifications (p_subscription) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : s_subscription
    THEN
        p_moreNotifs := bool(p_subscription : a_MoreNotifications)
    END
    ;
    
    decrement_subscription_LifetimeCounter (p_subscription) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : dom(a_LifetimeCounter) &
        a_LifetimeCounter(p_subscription) > 1 /* when == 1 => expiration */
    THEN
        a_LifetimeCounter(p_subscription) := a_LifetimeCounter(p_subscription) - 1
    END
    ;
    
    reset_subscription_LifetimeCounter (p_subscription) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : dom(a_LifetimeCounter)
    THEN
        a_LifetimeCounter(p_subscription) := a_lifetimeExpCount(p_subscription)
    END
    ;
    
    p_lifetimeCounter <-- get_subscription_LifetimeCounter (p_subscription) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : dom(a_LifetimeCounter)
    THEN
        p_lifetimeCounter := a_LifetimeCounter(p_subscription)
    END
    ;
    
    decrement_subscription_KeepAliveCounter (p_subscription) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : dom(a_KeepAliveCounter) &
        a_KeepAliveCounter(p_subscription) > 1 /* when == 1 => expiration */
    THEN
        a_KeepAliveCounter(p_subscription) := a_KeepAliveCounter(p_subscription) - 1
    END
    ;
    
    reset_subscription_KeepAliveCounter (p_subscription) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : dom(a_KeepAliveCounter)
    THEN
        a_KeepAliveCounter(p_subscription) := a_keepAliveExpCount(p_subscription)
    END
    ;
    
    p_keepAliveCounter <-- get_subscription_KeepAliveCounter (p_subscription) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : dom(a_KeepAliveCounter)
    THEN
        p_keepAliveCounter := a_KeepAliveCounter(p_subscription)
    END
    ;    
    
    set_subscription_MessageSent (p_subscription) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : s_subscription
    THEN
        a_MessageSent := a_MessageSent \/ {p_subscription}
    END
    ;
    
    p_firstMsgSent <-- get_subscription_MessageSent (p_subscription) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : s_subscription
    THEN
        p_firstMsgSent := bool(p_subscription : a_MessageSent)
    END
    ;
    
    set_subscription_PublishingEnabled (p_subscription, p_pubEnabled) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : s_subscription &
        p_pubEnabled : BOOL
    THEN
        IF p_pubEnabled = TRUE
        THEN
            a_PublishingEnabled := a_PublishingEnabled \/ {p_subscription}
        ELSE
            a_PublishingEnabled := a_PublishingEnabled - {p_subscription}
        END
    END
    ;
    
    p_pubEnabled <-- get_subscription_PublishingEnabled (p_subscription) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : s_subscription
    THEN
        p_pubEnabled := bool(p_subscription : a_PublishingEnabled)
    END
    ;
    
    set_subscription_SeqNum (p_subscription, p_nextSeqNum) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : dom(a_SeqNum) &
        p_nextSeqNum : t_sub_seq_num_i &
        p_nextSeqNum : t_sub_seq_num
    THEN
        a_SeqNum(p_subscription) := p_nextSeqNum
    END
    ;
    
    p_seqNumToSend <-- get_subscription_SeqNum (p_subscription) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : dom(a_SeqNum)
    THEN
        p_seqNumToSend :(p_seqNumToSend : t_sub_seq_num_i & p_seqNumToSend = a_SeqNum(p_subscription))
    END
    ;
    
    p_notificationQueue <-- get_subscription_notificationQueue (p_subscription) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : dom(a_pendingNotificationQueue)
    THEN
        p_notificationQueue :(p_notificationQueue : t_notificationQueue_i & 
                              p_notificationQueue = a_pendingNotificationQueue(p_subscription))
    END
    ;
    
    p_publishReqQueue <-- get_subscription_publishRequestQueue (p_subscription) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : dom(a_publishRequestQueue)
    THEN
        p_publishReqQueue :(p_publishReqQueue : t_publishReqQueue_i & 
                            p_publishReqQueue = a_publishRequestQueue(p_subscription))
    END
    ;
    
    p_monitoredItemQueue <-- get_subscription_monitoredItemQueue (p_subscription) =
    PRE
        p_subscription : t_subscription_i &
        p_subscription : dom(a_monitoredItemQueue)
    THEN
        p_monitoredItemQueue :(p_monitoredItemQueue : t_monitoredItemQueue_i & 
                               p_monitoredItemQueue = a_monitoredItemQueue(p_subscription))
    END

END