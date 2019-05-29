#include <stdio.h>
#include <stdlib.h>

FILE* logfile;
int g_wordcounter;

void print(int errno, void* ptr)
{
    switch (errno) {
    case 0: {
        printf("Error write to log file \"%s\".\n", (char*)ptr);
        break;
    }
    case 1: {
        printf("Error write to log file \"%s\".\n", (char*)ptr);
        break;
    }
    case 2: {
        printf("Memory allocation error.\n");
        break;
    }
    case 3: {
        printf("Error reading file \"%s\".\n", (char*)ptr);
        return;
    }
    case 4: {
        printf("Error input arguments(Usage: project <word> <path>)\n");
        break;
    }
    case 5: {
        printf("No words found.\n");
        break;
    }
    case 6: {
        printf("The program worked correctly\nFound words: %i\nPath to the "
               "file "
               "with the result: %s\n",
               g_wordcounter,
               (char*)ptr);
        return;
    }
    }
    fclose(logfile);
    exit(-1);
}
