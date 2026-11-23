#include "compound.h"

FILE *error_log()
{
    FILE *filePtr = NULL;

    if((filePtr = fopen("log.txt", "a")) == NULL)
        exit(EXIT_FAILURE);

    return filePtr;
}
