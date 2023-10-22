CC = g++
GCOV = gcov
FLAGS = -Wall -Werror -Wextra -std=c++17
OPTFLAGS = -pedantic
LTEST = -lgtest -lpthread
GOFLAGS = --coverage
GFLAGS = -fprofile-arcs -ftest-coverage
LIB = s21_matrix_oop.a

OS = $(shell uname)

OPENOS = vi
ifeq ($(shell uname -s), Linux)
		OPENOS = xdg-open
endif
ifeq ($(shell uname -s), Darwin)
		OPENOS = open -a "Google Chrome"
endif

.PHONY : all, clean, test, s21_matrix_oop.a gcov gcov_report
				leaks style style-fix check valgrind clean rebuild

BUILD_DIR = build
TEST_DIR = tests
BUILD_TEST_DIR = build_tests

S21_SOURCES = $(wildcard s21_*.cc)
S21_OBJECTS=$(addprefix $(BUILD_DIR)/, $(S21_SOURCES:.cc=.o))

TESTS = $(wildcard $(TEST_DIR)/test_*.cc)
TEST_OBJECTS=$(addprefix $(BUILD_TEST_DIR)/, $(notdir $(TESTS:.cc=.o)))

all: test

###############################################
# COMPILING AND RUNNING TESTS
###############################################

test: test_main
	./test

test_main: $(TEST_OBJECTS) $(LIB)
	$(CC) $(FLAGS) $(GOFLAGS) $^ -o test $(LTEST)

$(TEST_OBJECTS) : $(BUILD_TEST_DIR)/%.o : $(TEST_DIR)/%.cc $(TEST_DIR)/test_main.h
	mkdir -p $(BUILD_TEST_DIR)
	$(CC) $(FLAGS) $(OPTFLAGS) -c $< -o $@

###############################################
# COMPILING A STATIC LIBRARY
###############################################

$(LIB): $(S21_OBJECTS)
	ar -rcs $@ $^

$(S21_OBJECTS): $(BUILD_DIR)/%.o : %.cc $(LIB:.a=.h)
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) $(OPTFLAGS) $(GFLAGS) -c $< -o $@

###############################################
# CHECKS
###############################################

leaks: test_main
ifeq ($(OS), Linux)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test
else
	leaks -atExit -- ./test
endif

style: 
	@cp ../materials/linters/.clang-format ./
	@echo =COPY DONE!=
	@clang-format --style=google -n *.cc *.h
	@echo =CHECK COMPLETED=
	@rm -rf .clang-format
	@echo =REMOVE DONE!=

style-fix: 
	@cp ../materials/linters/.clang-format ./
	@echo =COPY DONE!=
	@clang-format --style=google -i *.cc *.h
	@echo =CHECK COMPLETED=
	@rm -rf .clang-format
	@echo =REMOVE DONE!=

# CPP-check
check:
	cppcheck --enable=all --suppress=missingIncludeSystem ./

valgrind:
	docker build -t ubuntu_01:latest .
	docker run -p 8085:8085 --name matrix01 ubuntu_01:latest
	docker rm matrix01
	docker rmi ubuntu_01:latest

###############################################
# CLEAN AND REBUILD
###############################################

clean:
	@echo ==Cleaning...==
	@rm -rf test
	@rm -rf $(LIB)
	@rm -rf $(BUILD_DIR)
	@rm -rf $(BUILD_TEST_DIR)
	@echo ==EVERYTHING REMOVED!==
	@echo ==Done!==

rebuild:
	$(MAKE) clean
	$(MAKE) all