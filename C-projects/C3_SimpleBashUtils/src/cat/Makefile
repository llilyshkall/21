s21_cat: s21_cat.c
	gcc -std=c11 -Wall -Wextra -Werror s21_cat.c -o s21_cat
test: s21_cat cat_test.sh
	sh cat_test.sh
test_leak: s21_cat cat_test.sh
	sh cat_test_leak.sh


all: s21_cat

clean: 
	rm s21_cat

rebuild: clean all