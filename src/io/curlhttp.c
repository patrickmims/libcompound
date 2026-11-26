#include "compound.h"

// CURLOPT_WRITEFUNCTION - callback for writing received data.  
static size_t callback(char *data, size_t size, size_t nmemb, void *arg)
{
    char *ptr = NULL;
    size_t realsize = nmemb;

    memory_t reference;
    memory_t *memory = NULL;
    memory = &reference;

    memory = (memory_t *)arg;

    if((ptr = realloc(memory->response, memory->size + realsize + 1)) == NULL)
        exit(EXIT_FAILURE);

    memory->memory = ptr;
    memcopy(&(memory->memory[memory->size]), data, realsize);
    memory->size += realsize;
    memory->memory[memory] = 0;

    return realsize;
}

void http()
{
    struct memory chunk = { 0 };
}
