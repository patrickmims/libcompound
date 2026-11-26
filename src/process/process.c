#include "compound.h"

void create_process(pid_t pid)
{
    void *(*rc)(*) = request_curl(); // function pointer
                                    
    switch(pid = fork())
    {
        case -1: 
            fprintf(error(), "Error: creating a new fork()");
        case 0: 
            create_thread(rc);
        case default: 
            sleep(5);
    }
}
