#Copyright Team S69

APP = 3D_Viewer
APPNAME = 3D_Viewer-1.0
LIB = viewer.a
TEST_LIB = tests.a

CC = gcc
GCOV = gcov
PROJECT_DIR = $(shell pwd)

ifeq ($(shell uname -p), arm)
		CC = gcc-13
		GCOV = gcov-13
endif

OPENOS = vi
ifeq ($(shell uname -s), Linux)
		OPENOS = xdg-open
else ifeq ($(shell uname -s), Darwin)
		OPENOS = open -a "Google Chrome"
else 
		OPENOS = open
endif

CFLAGS = -Wall -Werror -Wextra -std=c11
OPTFLAGS = -pedantic
GFLAGS = -fprofile-arcs -ftest-coverage
GLIB = -lgcov

CHECK_FLAGS = $(shell pkg-config --cflags check)
CHECK_LIB = $(shell pkg-config --libs check)

BACK_DIR = back
FRONT_DIR = front_qt
FRONT_BUILD = front_build
TEST_DIR = $(BACK_DIR)/tests
BUILD_DIR = $(BACK_DIR)/build

LIB_DIR = $(BACK_DIR)/back_lib
TEST_LIB_DIR = $(BUILD_DIR)/test_lib
TEST_BUILD_DIR = $(BUILD_DIR)/test_build

AUTO_BUILD = $(FRONT_DIR)/build

GCOV_DIR = $(BACK_DIR)/gcov_report
DOC_DIR = doc

BACK_SOURCES = $(wildcard $(BACK_DIR)/*.c)
BACK_HEAD = $(wildcard $(BACK_DIR)/*.h)
BACK_OBJECTS = $(addprefix $(LIB_DIR)/, $(BACK_SOURCES:$(BACK_DIR)/%.c=%.o))

TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c)
TEST_LIB_OBJECTS = $(addprefix $(TEST_LIB_DIR)/, $(BACK_SOURCES:$(BACK_DIR)/%.c=%.o))
TEST_OBJECTS = $(addprefix $(TEST_BUILD_DIR)/, $(TEST_SOURCES:$(TEST_DIR)/%.c=%.o))

.PHONY : all clean rebuild tests run \
				install uninstall doxygen-gen doxygen \
				valgrind style style-fix check  \
				rebuild gcov gcov_report dist dvi

all: install

$(APP): $(LIB)
	@mkdir -p $(FRONT_BUILD)
	@cd $(FRONT_DIR) && cmake -S . -B ../$(FRONT_BUILD)

install: $(APP)
	@cmake --build $(FRONT_BUILD) --target all
	@open $(shell pwd)/$(FRONT_BUILD)

uninstall:
	cd $(FRONT_BUILD) && $(MAKE) clean

dist:
	@$(MAKE) clean
	@touch $(APPNAME).tar.gz
	@tar --exclude=$(APPNAME).tar.gz --exclude=".*" --exclude="doc/*" -czvf $(APPNAME).tar.gz $(PROJECT_DIR)
	
check_dist:
	tar -ztvf $(APPNAME).tar.gz

run:
	./$(BACK_DIR)/test

###############################################
# COMPILING AND RUNNING TESTS WITH A TEST LIBRARY
###############################################

tests: $(BACK_DIR)/test
	@$(BACK_DIR)/test

$(BACK_DIR)/test: $(TEST_OBJECTS) $(BACK_DIR)/$(TEST_LIB)
	@$(CC) $(CFLAGS) $(OPTFLAGS) $(CHECK_FLAGS) $^ $(CHECK_LIB) $(GLIB) -o $(BACK_DIR)/test

$(TEST_OBJECTS): $(TEST_BUILD_DIR)/%.o: $(TEST_DIR)/%.c $(TEST_DIR)/test_me.h
	@mkdir -p $(TEST_BUILD_DIR)
	@$(CC) $(CFLAGS) $(OPTFLAGS) $(CHECK_FLAGS) -c $< -o $@

###############################################
# COMPILING A TEST BACK LIBRARY
###############################################

$(BACK_DIR)/$(TEST_LIB): $(TEST_LIB_OBJECTS)
	@ar -rcs $@ $^

$(TEST_LIB_OBJECTS): $(TEST_LIB_DIR)/%.o: $(BACK_DIR)/%.c $(BACK_HEAD:.a=.h)
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(TEST_LIB_DIR)
	@$(CC) $(CFLAGS) $(OPTFLAGS) $(GFLAGS) -c $< -o $@

###############################################
# COMPILING A STATIC LIBRARY
###############################################

$(LIB): $(BACK_OBJECTS)
	@ar -rcs $(FRONT_DIR)/$(LIB) $^

$(BACK_OBJECTS): $(LIB_DIR)/%.o: $(BACK_DIR)/%.c $(BACK_HEAD:.a=.h)
	@mkdir -p $(LIB_DIR)
	@$(CC) $(CFLAGS) $(OPTFLAGS) -c $< -o $@

###############################################
# GCOV_REPORT
###############################################

gcov: gcov_report
	@$(OPENOS) ./$(GCOV_DIR)/gcov_report.html

gcov_report: $(BACK_DIR)/$(TEST_LIB) tests $(GCOV_DIR)/gcov_report.html

$(GCOV_DIR)/gcov_report.html: $(BACK_DIR)/$(TEST_LIB) tests
	@mkdir -p $(GCOV_DIR)
	@gcovr -r . --gcov-executable $(GCOV) --html --html-details -o $(GCOV_DIR)/gcov_report.html

###############################################
# CHECKS
###############################################

# Leeks
valgrind: tests
	@valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --verbose $(BACK_DIR)/test

style: 
	@cp ../materials/linters/.clang-format ./
	@echo =COPY DONE!=
	@clang-format -n $(BACK_DIR)/*.c $(BACK_DIR)/*.h
	@clang-format -n $(TEST_DIR)/*.c $(TEST_DIR)/*.h
	@clang-format -n $(FRONT_DIR)/*.cpp $(FRONT_DIR)/*.h
	@echo =CHECK COMPLETED=
	@rm -rf .clang-format
	@echo =REMOVE DONE!=

style-fix: 
	@cp ../materials/linters/.clang-format ./
	@echo =COPY DONE!=
	@clang-format -i $(BACK_DIR)/*.c $(BACK_DIR)/*.h
	@clang-format -i $(TEST_DIR)/*.c $(TEST_DIR)/*.h
	@clang-format -i $(FRONT_DIR)/*.cpp $(FRONT_DIR)/*.h
	@echo =CHECK COMPLETED=
	@rm -rf .clang-format
	@echo =REMOVE DONE!=

# CPP-check
check:
	cppcheck --suppress=missingIncludeSystem -i$(FRONT_DIR)/QtGifImage -i$(FRONT_BUILD)/ ./

###############################################
# DOCUMENTATION
###############################################

dvi: doxygen

doxygen-gen: $(DOC_DIR)/3D_Viewer_doxyfile
	@doxygen $(DOC_DIR)/3D_Viewer_doxyfile

doxygen: gcov_report doxygen-gen 
	@$(OPENOS) ./doc/html/index.html

###############################################
# CLEAN AND REBUILD
###############################################

clean: 
# uninstall
	@echo ==Cleaning...==
	@rm -rf $(APP)
	@rm -rf $(GCOV_DIR)
	@rm -rf $(LIB_DIR)
	@rm -rf $(AUTO_BUILD)
	@rm -rf $(BUILD_DIR)
	@rm -rf $(BACK_DIR)/test
	@rm -rf $(FRONT_DIR)/$(LIB)
	@rm -rf $(FRONT_DIR)/build
	@rm -rf $(BACK_DIR)/$(TEST_LIB)
	@rm -rf $(DOC_DIR)/html
	@rm -rf $(FRONT_BUILD)
	@rm -rf $(APPNAME).tar.gz
	@echo ==EVERYTHING REMOVED!==
	@echo ==Done!==

rebuild : 
	$(MAKE) clean
	$(MAKE) all
