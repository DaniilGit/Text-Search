#include <stdio.h>
#include <stdlib.h>

#include "print.h"

FILE *logfile;
int filecounter;
int g_wordcounter;

unsigned short compare(int size, char *a, char *b) {
  for (int i = 0; i < size; i++)
    if (a[i] != b[i])
      return 0;
  return 1;
}

unsigned char qch(char ch) {
  if (ch == ' ' && ch == '(' && ch == ')' && ch == '[' && ch == ']' &&
      ch == '{' && ch == '}' && ch == ',' && ch == '.' && ch == '<' &&
      ch == '>' && ch == '/' && ch == '|' && ch == '\\' && ch == '!')
    return 1;
  return 0;
}

void file_search(char *path, char *word) {
  FILE *file;
  if ((file = fopen(path, "r")) == NULL) {
    print(3, path);
    return;
  }

  fseek(file, 0, SEEK_END);
  int size = ftell(file);

  int wordsize = 0;
  while (word[wordsize] != '\0')
    wordsize++;

  char *buffer = (char *)malloc(sizeof(char) * wordsize);
  if (buffer == NULL)
    print(2, NULL);
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
