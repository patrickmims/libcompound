#include "compound.h"

// https://curl.se/libcurl/c/CURLOPT_WRITEFUNCTION.html  

void create_process(pid_t pid, void (*fn)(), void *arg)
{
    // list_t (*ftp)() = wrapper_ftp; // function pointer
    // pthread_t thread;

    list_t l; 
    list_t *list = NULL;
    list = &l;
    list = (list_t *)memory;

    printf("Parent [ %d ]\n", getpid());

    switch(pid = fork())
    {
        case -1:
            fprintf(error_log(), "Error: creating a new fork()");
        case 0:
            // list = (list_t *)arg;
            // needs to return a list_t
            fn(list);
            exit(EXIT_SUCCESS);
        default:
            sleep(5);
            break;
    }

    printf("new l.item => %d\n", list->item);
}

