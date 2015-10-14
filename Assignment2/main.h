//
//  main.h
//  Assignment2
//
//  Created by James Eggers on 16/02/2015.
//  Copyright (c) 2015 James Eggers. All rights reserved.
//

#ifndef Assignment2_main_h
#define Assignment2_main_h

#define NUM_THREADS 10

struct buffer {
    int num_items;
    pthread_cond_t c_cond;
    pthread_cond_t p_cond;
    pthread_mutex_t lock;
    pthread_mutex_t c_1lock;
    pthread_mutex_t c_2lock;
};

#endif
