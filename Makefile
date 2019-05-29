PATHBIN = bin/
PATHSRC = src/
PATHTEST = test/
PATHBUILDSRC = build/src/
PATHBUILDTEST = build/test/

all: bin build build/src $(PATHBIN)project

$(PATHBIN)project: $(PATHBUILDSRC)main.o $(PATHBUILDSRC)print.o $(PATHBUILDSRC)dir_pass_windows.o $(PATHBUILDSRC)dir_pass_linux.o $(PATHBUILDSRC)file_search.o
	gcc $(PATHBUILDSRC)main.o $(PATHBUILDSRC)print.o $(PATHBUILDSRC)dir_pass_windows.o $(PATHBUILDSRC)file_search.o $(PATHBUILDSRC)dir_pass_linux.o -o $(PATHBIN)project

$(PATHBUILDSRC)file_search.o: $(PATHSRC)file_search.c
	gcc -Wall -Werror -c $(PATHSRC)file_search.c -o $(PATHBUILDSRC)file_search.o

$(PATHBUILDSRC)main.o: $(PATHSRC)main.c
	gcc -Wall -Werror -c $(PATHSRC)main.c -o $(PATHBUILDSRC)main.o

$(PATHBUILDSRC)print.o: $(PATHSRC)print.c
	gcc -Wall -Werror -c $(PATHSRC)print.c -o $(PATHBUILDSRC)print.o

$(PATHBUILDSRC)dir_pass_windows.o: $(PATHSRC)dir_pass_windows.c
	gcc -Wall -Werror -c $(PATHSRC)dir_pass_windows.c -o $(PATHBUILDSRC)dir_pass_windows.o

$(PATHBUILDSRC)dir_pass_linux.o: $(PATHSRC)dir_pass_linux.c
	gcc -Wall -Werror -c $(PATHSRC)dir_pass_linux.c -o $(PATHBUILDSRC)dir_pass_linux.o

test: bin build build/test $(PATHBIN)project_test

$(PATHBIN)project_test: $(PATHBUILDTEST)main.o $(PATHBUILDTEST)test.o $(PATHBUILDTEST)print.o $(PATHBUILDTEST)file_search.o
	gcc -Wall $(PATHBUILDTEST)main.o $(PATHBUILDTEST)test.o $(PATHBUILDTEST)print.o $(PATHBUILDTEST)file_search.o -o $(PATHBIN)project_test -lm

$(PATHBUILDTEST)test.o: $(PATHTEST)test.c
	gcc -Wall -Werror -c -I thirdparty -I src $(PATHTEST)test.c -o $(PATHBUILDTEST)test.o

$(PATHBUILDTEST)main.o: $(PATHTEST)main.c
	gcc -Wall -Werror -c -I thirdparty -I src $(PATHTEST)main.c -o $(PATHBUILDTEST)main.o

$(PATHBUILDTEST)print.o: $(PATHSRC)print.c
	gcc -Wall -Werror -c -I thirdparty -I src $(PATHSRC)print.c -o $(PATHBUILDTEST)print.o

$(PATHBUILDTEST)file_search.o: $(PATHSRC)file_search.c
	gcc -Wall -Werror -c -I thirdparty -I src $(PATHSRC)file_search.c -o $(PATHBUILDTEST)file_search.o

bin:
	mkdir bin

build:
	mkdir build

build/src:
	mkdir build/src

build/test:
	mkdir build/test

clean:
	rm -rf build/*.o $(PATHBUILDTEST)*.o bin/project_test.o bin/ptoject
	rm -rf build bin

.PHONY: clean
