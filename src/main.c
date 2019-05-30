#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* logfile;
int filecounter;
int g_wordcounter;

#include "dir_pass.h"
#include "file_search.h"
#include "print.h"

int main(int argc, char** argv)
{
    g_wordcounter = 0;
    filecounter = 1;

    if (argc < 3)
        print(4, NULL);

    char* word;
    char* path;
    char* logpath;
    int i = 0;
    word = (char*)malloc(sizeof(char));
    path = (char*)malloc(sizeof(char) * 256);
    logpath = (char*)malloc(sizeof(char) * 256);

    if (word == NULL || path == NULL || logpath == NULL)
        print(2, NULL);

    printf("Write log file:");
    scanf("%s", logpath);

    strcpy(path, argv[2]);

    while (path[i] != '\0')
        i++;
    if (path[i - 1] == '/')
        path[i - 1] = '\0';

    strcpy(word, argv[1]);

    if ((logfile = fopen(logpath, "w")) == NULL)
        print(1, logpath);

    if (path[0] == '/')
        dir_pass_linux(path, word);
    else
        dir_pass_windows(path, word);

    fclose(logfile);

    if (filecounter == 1)
        print(5, NULL);
    else
        print(6, logpath);

    free(word);
    free(path);
    free(logpath);

    return 0;
}
