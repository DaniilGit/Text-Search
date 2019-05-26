#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dir_pass.h"
#include "file_search.h"
#include "print.h"

FILE *logfile;

int dir_pass_windows(char *path, char *word) {
  struct dirent *file_info;

  DIR *dir;
  char buffer[300];
  strcpy(buffer, path);

  dir = opendir(path);

  while ((file_info = readdir(dir)) != NULL) {

    if (file_info->d_name[0] == '.' &&
        ((file_info->d_name[1] == '\0') ||
         (file_info->d_name[1] == '.' && file_info->d_name[2] == '\0')))
      continue;

    if (file_info->d_type == 16) {
      char *name_dir = file_info->d_name;
      strcat(path, "\\");
      strcat(path, name_dir);
      dir_pass_windows(path, word);
    } else {
      char *name_file = file_info->d_name;
      strcat(path, "\\");
      strcat(path, name_file);

    //сюда функцию
    }
    strcpy(path, buffer);
  }
  closedir(dir);
  return 0;
}