.PHONY: all build replication mk install uninstall clean dvi dist tests leaks cpplint gcov_report test
CXX = g++ -std=c++17
BD=../build/
QMAKE=$(BD)
FLAGS = #-Wall -Wextra -Werror
CFLAGS= -fprofile-arcs -ftest-coverage
FILES = SmartCalc2_0/calc_model.cpp
GCOV = -fprofile-arcs -ftest-coverage
CLIBS = -lgtest -lgtest_main
APP = $(QMAKE)SmartCalc2_0.app
APPDIR=$(HOME)/Applications/SmartCalc2_0/
APP_EXE=$(APPDIR)/SmartCalc2_0.app/Contents/SmartCalc2_0

all: clean gcov_report

build: clean mk #replication
	cd $(BD); qmake ../src/SmartCalc2_0/SmartCalc2_0.pro
	make -C $(BD)
	cd $(BD); rm -rf *.c *.h *.cpp *.ui *.o

replication: 
	cp ../src/SmartCalc2_0/SmartCalc2_0.pro $(BD)
	cp *.h *.cpp *.ui $(BD)

mk:
	@mkdir $(BD) 

install: build 
	@mkdir $(APPDIR) || echo "Directory already exists. Skip."
	cp -rf $(APP) $(APPDIR)
	make clean

uninstall: 
	rm -rf $(BD)
	rm -rf $(APPDIR)

dvi:
	@echo "watch ReadMe.md in src folder"

clean:
	rm -rf *.o *.out *.gcda *.gcno *.info *.gch *.a test *.gcov ./report
	rm -rf $(BD)

test:
	$(CXX) $(FLAGS) $(FILES) calc_gtest.cpp -o test.out $(CLIBS)
	./test.out

tests: test

gcov_report: clean
	$(CXX) $(GCOV) calc_gtest.cpp $(FILES) $(CLIBS) -o gcov_report.out
	./gcov_report.out
	lcov -t "gcov_report" -o gcov_report.info -c -d .
	genhtml -o report gcov_report.info
	open ./report/index.html

dist: clean
	tar -cvf $(APPDIR)../SmartCalc2_0.tar $(APPDIR)
	gzip $(APPDIR)../SmartCalc2_0.tar

leaks: clean test
	MallocStackLogging=1 leaks -atExit -- ./test.out

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem  *.cpp SmartCalc2_0/*cpp -DTEST

valgrind:
		valgrind --leak-check=full  --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind.txt ./a.out

linters:
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=cpp *.cpp SmartCalc2_0/*.cpp SmartCalc2_0/*.h