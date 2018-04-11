all: p3.o

p3.o: readInto2DArray.c
	gcc -g readInto2DArray.c -o p3.o -lpthread
sodoku.o: sodoku.c
		gcc -g sodoku.c -o sodoku.o -lpthread

clean:
	rm *.o
