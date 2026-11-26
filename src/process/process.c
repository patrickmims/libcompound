#include "compound.h"

void create_process(pid_t pid)
{
    list_t (*ftp)() = wrapper_ftp; // function pointer
    pthread_t thread;

    list_t list;
    list.item = 0;

    printf("Parent [ %d ]\n", getpid());

    // projects need investments and investments need capital
    switch(pid = fork())
    {
        case -1:
            fprintf(error_log(), "Error: creating a new fork()");
        case 0:
            list = wrapper_ftp(list);
            printf("new item value => %d\n", list.item);
            exit(EXIT_SUCCESS);
        default:
            sleep(5);
            break;
    }

    printf("new l.item => %d\n", list.item);
}
/**
 *  
 */
