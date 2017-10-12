/*
 *  Copyright (C) 2017 Systerel and others.
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

#include "session_async_bs.h"

#include "sopc_services_api.h"
#include "sopc_toolkit_config.h"
#include "util_b2c.h"

static constants__t_session_i unique_session_to_activate = constants__c_session_indet;
static constants__t_user_i unique_session_to_activate_user = constants__c_user_indet;
static constants__t_session_i unique_session_to_create = constants__c_session_indet;
static constants__t_channel_config_idx_i unique_session_to_create_idx = constants__c_channel_config_idx_indet;

void session_async_bs__INITIALISATION(void)
{
}

/*--------------------
   OPERATIONS Clause
  --------------------*/
void session_async_bs__add_session_to_activate(
   const constants__t_session_i session_async_bs__session,
   const constants__t_user_i session_async_bs__user,
   t_bool * const session_async_bs__ret)
{
  if(unique_session_to_activate_user == constants__c_user_indet){
    unique_session_to_activate_user = session_async_bs__user;
    unique_session_to_activate = session_async_bs__session;
    *session_async_bs__ret = true;
  }else{
    *session_async_bs__ret = false;
  }  
}

void session_async_bs__add_session_to_create(
   const constants__t_session_i session_async_bs__session,
   const constants__t_channel_config_idx_i session_async_bs__channel_config_idx,
   t_bool * const session_async_bs__ret)
{
  if(unique_session_to_create == constants__c_session_indet){
    unique_session_to_create_idx = session_async_bs__channel_config_idx;
    unique_session_to_create = session_async_bs__session;
    *session_async_bs__ret = true;
  }else{
    *session_async_bs__ret = false;
  }  
}

void session_async_bs__get_and_remove_session_user_to_activate(
   const constants__t_session_i session_async_bs__session,
   constants__t_user_i * const session_async_bs__user){
  if(session_async_bs__session == unique_session_to_activate){
    *session_async_bs__user = unique_session_to_activate_user;
    unique_session_to_activate_user = constants__c_user_indet;
  }else{
    *session_async_bs__user = constants__c_user_indet;
  }
}

void session_async_bs__get_and_remove_session_to_create(
   const constants__t_channel_config_idx_i session_async_bs__channel_config_idx,
   constants__t_session_i * const session_async_bs__session){
  if(session_async_bs__channel_config_idx == unique_session_to_create_idx){
    *session_async_bs__session = unique_session_to_create;
    unique_session_to_create = constants__c_session_indet;
  }else{
    *session_async_bs__session = constants__c_session_indet;
  }
}

void session_async_bs__client_gen_activate_orphaned_session_internal_event(
   const constants__t_session_i session_async_bs__session,
   const constants__t_channel_config_idx_i session_async_bs__channel_config_idx){
  /* TODO: check integer casts */
  SOPC_Services_EnqueueEvent(SE_TO_SE_ACTIVATE_ORPHANED_SESSION,
                             (uint32_t) session_async_bs__session,
                             NULL,
                             (uint32_t) session_async_bs__channel_config_idx);
}

void session_async_bs__client_gen_activate_user_session_internal_event(
   const constants__t_session_i session_async_bs__session,
   const constants__t_user_i session_async_bs__user){
  /* TODO: check integer casts */
    SOPC_Services_EnqueueEvent(SE_TO_SE_ACTIVATE_SESSION,
                               (uint32_t) session_async_bs__session,
                               NULL,
                               (uint32_t) session_async_bs__user);

}

void session_async_bs__client_gen_create_session_internal_event(
   const constants__t_session_i session_async_bs__session,
   const constants__t_channel_config_idx_i session_async_bs__channel_config_idx){
  /* TODO: check integer casts */
    SOPC_Services_EnqueueEvent(SE_TO_SE_CREATE_SESSION,
                               (uint32_t) session_async_bs__session,
                               NULL,
                               (uint32_t) session_async_bs__channel_config_idx);
}