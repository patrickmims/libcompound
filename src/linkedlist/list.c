#include "compound.h"

/*
FILE *error()
{
    FILE *filePtr = NULL;

    if((filePtr = fopen("error.txt", "a")) == NULL)
        exit(EXIT_FAILURE);

    return filePtr;
}
*/

void insert(list_t **list, int item)
{
    static int i = 0;

    list_t n;
    list_t *node = &n; 

    node = (list_t *)memory();

    node->data[i] = item;
    node->next = *list;

    *list = node;

    i += i + 1;
}

// pressure is force exerted against the walls by gas particles.
