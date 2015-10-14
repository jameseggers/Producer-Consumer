//
//  consumer.c
//  Assignment2
//
//  Created by James Eggers on 11/02/2015.
//  Copyright (c) 2015 James Eggers. All rights reserved.
//

#include "consumer.h"
#include "main.h"
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t lock;

void * new_consumer(void * new_buffer) {
    struct buffer * buffer = (struct buffer *)new_buffer;
    int id = rand();
    
    while (1) {
        if (buffer->num_items > 0) {
            buffer->num_items--;
            printf("Con (%d): %d\n", id, buffer->num_items);
        } else {
            pthread_cond_signal(&(buffer->p_cond));
            pthread_mutex_lock(&(buffer->c_2lock));
            pthread_cond_wait(&(buffer->c_cond), &(buffer->c_2lock));
            pthread_mutex_unlock(&(buffer->c_2lock));
        }
    }
}