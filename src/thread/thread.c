#include "compound.h"

/* create_thread - Generic wrapper. 
 * pthread thread - The thread passed in from process.c.
 * void *(*fn)(void *) - The function that will run in the thread. (function ptr).
 * void *args - The parameters that to be passed into fn.
 * */

void create_thread(pthread_t thread, void *(*fn)(void *), void *arg)
{
    void *rc;

    if (pthread_create(&thread, NULL, fn, arg) != 0)
        fprintf(stderr, "Error: pthread_create()");

    int s = pthread_join(thread, &rc); // 1. wait for the thread to finish.

    printf("create_thread() - [ %d ] \n", s);
}

