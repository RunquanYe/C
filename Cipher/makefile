# ------------------------------------------------------------------------
# Author: Runquan Ye
# Date: 2018/11
# Description: makefile for a simple cipher in C
# ------------------------------------------------------------------------

all: functions.o main.o
	touch data.txt
	gcc functions.o main.o -o cipher

main.o:  main.c functions.h
	gcc -c main.c

functions.o: functions.h functions.c
	gcc -c functions.c 

encrypt: 
	./cipher e GOODMORNING data.txt edata.txt

decrypt: 
	./cipher d GOODMORNING cipher ddata.txt

test:
	./cipher e GOODMORNING data.txt edata.txt
	./cipher d GOODMORNING edata.txt ddata.txt
	diff -s data.txt ddata.txt

clean:
	rm -f *.o +wdata.txt p edata.txt ddata.txt cipher
