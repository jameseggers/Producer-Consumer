//
//  producer.c
//  Assignment2
//
//  Created by James Eggers on 11/02/2015.
//  Copyright (c) 2015 James Eggers. All rights reserved.
//

#include "producer.h"
#include "main.h"
#include <pthread.h>

pthread_mutex_t lock;

void * new_producer(void * new_buffer) {
    struct buffer * buffer = (struct buffer *)new_buffer;
    int id = rand();
    
    while (1) {
        if (buffer->num_items > 31) {
            printf(" ");
            pthread_cond_signal(&(buffer->c_cond));
            pthread_mutex_lock(&(buffer->c_1lock));
            pthread_cond_wait(&(buffer->p_cond), &(buffer->c_1lock));
            pthread_mutex_unlock(&(buffer->c_1lock));
        } else {
            buffer->num_items++;
            printf("Pro (%d): %d\n", id, buffer->num_items);
        }
    }
}