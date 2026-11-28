#ifndef COMPOUND_H
#define COMPOUND_H

#include <arpa/inet.h>
#include <curl/curl.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// #include "process.h"
// #include "linkedlist.h"

typedef struct Memory
{
    char *response;
    size_t size;
} memory_t;

typedef struct List 
{
    int item;
    int *data;
    struct Node *next;
} list_t;

FILE *error_log(); 
void *request_curl();
void create_process(pid_t, void (*)(), void *);
void create_thread(pthread_t, void *(*)(), void *);
void network_init(); 
void socket_server();
void *memory();
void ftp();
void http();

void insert(list_t **, int);
list_t wrapper_ftp(list_t);

/**
 * void read_json();
 * void write_json();
 */
#endif
