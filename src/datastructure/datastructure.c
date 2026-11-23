#include "compound.h"

void *memory()
{
    void *memory = NULL;

    if((memory = malloc(sizeof(void *))) == NULL)
    {
        fprintf(error_log(), "Error: *memory()");
    }

    return memory;
}
