CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
SOURCES = s21_calculation.c s21_helper_functions.c s21_parcing.c s21_rpn.c s21_smart_calc.c s21_validator.c TESTS.c
MAT = -lm
OS = $(shell uname)

ifeq ($(OS),Linux)
    det_OS = -lcheck -lm -lrt -lpthread -lsubunit
		project = new.pro
		inst = cd qt_calc && cd new && qmake && make && make clean && rm Makefile && mkdir -p ../../build && mv $(project) ../../build/
else
    det_OS = -lcheck -lm -lpthread
		project = new.app
		inst = cd qt_calc && cd new && qmake new.pro && make && make clean && rm Makefile && mkdir -p ../../build && mv new.app/$(UI_BIN) ../../build

endif

all : clean dist gcov_report dvi

dvi:
	open ./documentation.md

install: clean uninstall
	$(inst)

dist: clean_all install
	mkdir -p dist
	cp  -R ./build/$(project) ./dist/$(project)
	cp ./documentation.md ./dist/documentation.md
	cd ./dist && tar cvzf calculator.tgz *
	cd ./dist && rm -R $(project) documentation.md
	make clean

uninstall:
	rm -rf build ./build/.qmake.stash

test: clean
	$(CC) $(CFLAGS) --coverage $(SOURCES) -o test $(det_OS)
	./test

gcov_report: test
	./test
	lcov -t "result" -o res.info -c -d .
	genhtml -o report res.info
	open report/index.html

check:
	cp ../materials/linters/.clang-format ./
	clang-format -style=Google -i *.c *.h
	clang-format -style=Google -n *.c *.h
	rm .clang-format

clean:
	rm -rf report *.gc* *.o *.info *.a test.dSYM test gch ./new.pro/.qmake.stash compose-dev.yaml 

clean_dist:
	rm -rf dist

clean_all: clean clean_dist uninstall

rebuild: clean_all all 
