#include <stdio.h>
#include <stdlib.h>

#include "print.h"

FILE* logfile;
int filecounter;
int g_wordcounter;

unsigned short compare(int size, char* a, char* b)
{
    for (int i = 0; i < size; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}

int file_search(char* path, char* word)
{
    FILE* file;
    if ((file = fopen(path, "r")) == NULL) {
        print(3, path);
        return -1;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);

    int wordsize = 0;
    while (word[wordsize] != '\0')
        wordsize++;

    char* buffer = (char*)malloc(sizeof(char) * wordsize);
    if (buffer == NULL) {
        print(2, NULL);
        return -1;
    }
    int line = 0;
    int linepos = 0;
    int lineend = 0;
    int pos = 0;
    int wordcounter = 1;

    unsigned short once = 1;
    unsigned short eof = 0;
    while (!eof) {
        fseek(file, linepos, SEEK_SET);
        for (int i;;) {
            i = ftell(file);
            char ch = '\0';
            fread(&ch, 1, 1, file);
            if (ch == '\n') {
                lineend = i - 1;
                break;
            }
            if (i == size) {
                lineend = i;
                eof = 1;
                break;
            }
        }

        line++;
        pos = linepos;

        char* linestr = (char*)malloc(sizeof(char) * (lineend - linepos + 2));
        if (linestr == NULL) {
            print(2, NULL);
            return -1;
        }
        fseek(file, linepos, SEEK_SET);
        fread(linestr, lineend - linepos + 1, 1, file);
        linestr[lineend - linepos + 1] = '\0';

        while (pos <= lineend - wordsize + 1) {
            fseek(file, pos, SEEK_SET);
            fread(buffer, wordsize, 1, file);
            if (compare(wordsize, word, buffer)) {
                if (once) {
                    once = 0;
                    fprintf(logfile,
                            "%i) The path to the file: %s\nWord:%s\n",
                            filecounter,
                            path,
                            word);
                    filecounter++;
                }
                fprintf(logfile,
                        "String number(%i): %i\nString: %s\n\n",
                        wordcounter,
                        line,
                        linestr);
                pos += wordsize;
                wordcounter++;
                g_wordcounter++;
            }
            pos++;
        }
        linepos = lineend + 2;
        free(linestr);
    }
    free(buffer);
    return 0;
}
