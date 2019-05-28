#include "../thirdparty/ctest.h"
#include "file_search.c"
#include "print.h"
#include <stdio.h>
#include <stdlib.h>

CTEST(file_search, file_search)
{
    FILE* test;
    test = fopen("test_file.txt", "w");

    fprintf(test, "test\n");
    fprintf(test, "t.e.s.t\n");
    fprintf(test, "one, two, three\n");
    fprintf(test, "test, one, two\n");

    fclose(test);
}