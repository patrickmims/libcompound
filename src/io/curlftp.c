#include "compound.h"

list_t wrapper_ftp(list_t l)
{
    //l.item = 5;
    printf("Child [ %d ] \n", getpid());
    printf("Parent inside of process[ %d ] \n", getppid());
    printf("item %d\n", l.item);
    l.item = 50;

    return l;
    /*
    char LOCAL[] = "local_test_file.txt"; 
    CURL *curl = NULL;
    CURLcode rc;
    FILE *hd = NULL;
    curl_off_t filesize;
    struct stat file_info;

    struct curl_slist *list = NULL;
    //static const char buf_1[] = "RNFR " UPLOAD_FILE_AS;
    //static const char buf_2[] = "RNTO " RENAME_FILE_TO;

    if((hd = fopen(LOCAL, "rb")) == NULL) // <[ create a file pointer to the file ]
        printf("Could not open '%s': %s\n", LOCAL, strerror(errno));
        // return 2;

    filesize = file_info.st_size;
    */
}
