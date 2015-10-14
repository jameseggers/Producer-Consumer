//
//  main.c
//  Assignment2
//
//  Created by James Eggers on 11/02/2015.
//  Copyright (c) 2015 James Eggers. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "main.h"
#include "producer.h"
#include "consumer.h"

int main(int argc, const char * argv[]) {
    pthread_t threads[NUM_THREADS];
    struct buffer * new_buffer = malloc(sizeof(struct buffer));
    new_buffer->num_items = 0;
    
    pthread_mutex_init(&(new_buffer->lock), NULL);
    pthread_mutex_init(&(new_buffer->c_1lock), NULL);
    pthread_mutex_init(&(new_buffer->c_2lock), NULL);
    pthread_cond_init(&(new_buffer->c_cond), NULL);
    pthread_cond_init(&(new_buffer->p_cond), NULL);
    
    pthread_create(&threads[0], NULL, new_producer, (void*)new_buffer);
    pthread_create(&threads[1], NULL, new_consumer, (void*)new_buffer);
    while(1) { printf(""); }
    
    return 0;
}


