all: operations.h operations.o main.o
	touch data.txt
	gcc -o store operations.o main.o

run:
	./store data.txt

clean:
	rm -f *.o store 
