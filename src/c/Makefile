CC = gcc
CFLAGC = -Wall -Werror -Wextra -c -g -std=c11
GCOVFLAGS := --coverage
SOURCES := ./c/Tests/*.c
SOURCES_M := ./c/Main_logic/*.c
SOURCES_N := ./c/Polish_notation/*.c
SOURCES_S := ./c/Stacks/*.c
OBJECTS := *.o
LDFLAGS := -lcheck -fprofile-arcs
TEXI2DVI = cp
INSTRUCTION = ./c/instruction.pdf ./

all: install test gcov_report

install:
	cmake CMakeLists.txt
	make
	rm Makefile
	cp ./c/Makefile ./

uninstall:
	rm cmake_install.cmake
	rm CMakeCache.txt
	rm -rf SmartCalc_autogen
	rm -rf CMakeFiles
	rm -rf SmartCalc.app

tests: tests gcov_report

true_dvi:
	texi2dvi ./instriction.tex

dvi:
	$(TEXI2DVI) $(INSTRUCTION)
	open $(INSTRUCTION_DVI)

dist:
	mkdir gcc-99
	cp -r ./c ./gcc-99
	rm -rf ./gcc-99/Tests
	cp *.cpp ./gcc-99
	cp *.h ./gcc-99
	cp *.ui ./gcc-99
	cp Makefile ./gcc-99
	cp CMakeLists.txt ./gcc-99
	tar -zcvf gcc-99.tar.gz ./gcc-99
	rm -rf gcc-99

test:
	$(CC) $(CFLAGC) $(GCOVFLAGS) $(SOURCES_N) $(SOURCES_S) $(SOURCES_M) $(SOURCES)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	./$@

gcov_report:
	gcovr --html-details report.html
	open report.html


rebuild: uninstall clean all

style:
	clang-format -n ./*/*.c ./*/*.h ../*.cpp ../*.h

clean:
	rm -rf *.a
	rm -rf test
	rm -rf *.o
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.html
	rm -rf *.css
	rm -rf *.pdf