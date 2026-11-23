#ifndef COMPOUND_H
#define COMPOUND_H

#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "process.h"
#include "linkedlist.h"

typedef struct Node
{
    int *data;
    struct Node *next;
} list_t;

void create_process(pid_t);
void curl_request();
void network_init(); 

void insert(list_t **, int);


#endif
