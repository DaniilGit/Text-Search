#include "../thirdparty/ctest.h"
#include "file_search.h"
#include "print.h"
#include <stdio.h>
#include <stdlib.h>

//FILE* logfile;
int filecounter;
int g_wordcounter;

CTEST(file_search, file_search)
{
    FILE* logfile;
    filecounter = 1;
    g_wordcounter = 0;
    FILE* test;

    int result = 6;
    int expected = 0;

    test = fopen("test_file.txt", "w");
    logfile = fopen("result.txt", "w");

    fprintf(test, "test\n");
    fprintf(test, "t.e.s.t\n");
    fprintf(test, "one, two, three\n");
    fprintf(test, "test, one, two\n");

    result = file_search("test_file.txt", "test");

    fclose(test);
    fclose(logfile);

    ASSERT_EQUAL(expected, result);
    
    remove("result.txt");
}
CTEST(Separator_test, file_search)
{
    char a[] = "separator";
    char b[] = "separator";
    int size = 9;
    int exp = 1;

    int rl = compare(size, a, b);

    ASSERT_EQUAL(exp, rl);
}
