s21_grep: s21_grep.c grep.c chars.c
	gcc -std=c11 -Wall -Wextra -Werror grep.c s21_grep.c chars.c -o s21_grep
test: test.c
	gcc -Wall -Wextra -Werror test.c -o test
	./test
	rm grep.txt s21_grep.txt test

all: s21_grep

clean: 
	rm s21_grep

rebuild: clean all