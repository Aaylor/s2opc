/*
 * buffer.h
 *
 *  Created on: Jul 22, 2016
 *      Author: vincent
 */

#ifndef INGOPCS_BUFFER_H_
#define INGOPCS_BUFFER_H_

typedef struct Buffer {
    uint32_t max_size;
    uint32_t size;
    uint32_t position;
    UA_Byte* data;
} Buffer;

#endif /* INGOPCS_BUFFER_H_ */
