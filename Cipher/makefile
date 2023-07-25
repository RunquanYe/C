all: functions main
	touch data.txt
	gcc -o cipher functions.o main.o

main: functions.h main.c
	gcc -c main.c

functions: functions.h functions.c
	gcc -c functions.c -o functions.o 

enc: 
	./cipher e GOODMORNING data.txt edata.txt

dec: 
	./cipher d GOODMORNING cipher ddata.txt

test:
	./cipher e GOODMORNING data.txt edata.txt
	./cipher d GOODMORNING edata.txt ddata.txt
	diff -s data.txt ddata.txt

clean:
	rm -f *.o +wdata.txt p edata.txt ddata.txt cipher
