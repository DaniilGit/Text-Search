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
