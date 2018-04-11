all: p3.o

p3.o: readInto2DArray.c
	gcc -g readInto2DArray.c -o p3.o -lpthread

clean:
	rm *.o
