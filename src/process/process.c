#include "compound.h"

void create_process(pid_t pid)
{
    list_t (*ftp)() = wrapper_ftp; // function pointer
    pthread_t thread;

    list_t l;
    l.item = 0;

    printf("Parent [ %d ]\n", getpid());

    // projects need investments and investments need capital
    switch(pid = fork())
    {
        case -1:
            fprintf(error_log(), "Error: creating a new fork()");
        case 0:
            // create_thread(thread, ftp, list);
            l = wrapper_ftp(l); 
            printf("new l.item => %d\n", l.item);
            exit(EXIT_SUCCESS);
        default:
            sleep(5);
            break;
    }

    printf("new l.item => %d\n", l.item);
}
