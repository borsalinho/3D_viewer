.PHONY: test

FLAGS = -Wall -Werror -Wextra -std=c++17
OS := $(shell uname)
CHECK_FLAGS = -lgtest -lgmock -pthread

ifeq ($(OS), Linux)
	OPEN_CMD = xdg-open
	MEM_CHECK = valgrind --tool=memcheck --trace-children=yes --track-origins=yes --leak-check=full
else
	OPEN_CMD = open
	MEM_CHECK = leaks --atExit -- ./test
endif

all: clean install

install:
	make clean
	mkdir build
	mv Makefile Makefile.old
ifeq ($(OS), Linux)
	qmake6 && make && make clean && rm Makefile && mv  Maze ../build/	
else
	qmake && make && make clean && rm Makefile && mv Maze.app/Contents/MacOS/Maze build/
endif
	mv Makefile.old Makefile

uninstall:
	rm -rf build

clean:
	rm -rf build
	rm -rf a.out test *.o *.a report report.info gcov *.tgz *.gcno *gcda *.gcov .*.stash
	rm -rf *.o *.app

dvi:
	open index.html

dist:
	tar cvzf archive_Maze.tgz build/ 

open:
	open build/Maze

clang:
	cp ../../materials/linters/.clang-format ./
	clang-format -n *.cpp controller/*.* model/*.* view/*.*
	rm .clang-format

clang_check:
	cp ../../materials/linters/.clang-format ./
	clang-format -i *.cpp controller/*.* model/*.* view/*.*
	rm .clang-format	
