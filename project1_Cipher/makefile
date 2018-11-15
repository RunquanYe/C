all: functions.h functions.o main.o
	touch data.txt
	gcc -o cipher functions.o main.o

main.o: functions.h main.c
	gcc -c main.c

functions.o: functions.h functions.c
	gcc -c functions.c

enc: 
	./cipher e GOODMORNING data edata

dec: 
	./cipher d GOODMORNING cipher ddata

test:
	./cipher e GOODMORNING data edata
	./cipher d GOODMORNING edata ddata
	diff -s data ddata

clean:
	rm -f *.o p edata ddata
