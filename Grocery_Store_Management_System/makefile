# ------------------------------------------------------------------------
# Author: Runquan Ye
# Date: 2018/11
# Description: makefile for the Grocery Store Management System in C
# ------------------------------------------------------------------------

all: main.o operations.o
	touch data.txt
	gcc -o store operations.o main.o

main: operations.h main.c
	gcc -c main.c

operations: operations.h operations.c
	gcc -c operations.c

run:
	./store data.txt

clean:
	rm *.o store 