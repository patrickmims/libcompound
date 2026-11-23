#include "compound.h"

void create_process()
{
    pid_t curl_pid;
    switch(curo_pid = fork())
    {
        case -1: 
            fprintf(error(), "Error: creating a new fork()");
        case 0: 
            curl_request();
        case default: 
            sleep(5);
    }
}
