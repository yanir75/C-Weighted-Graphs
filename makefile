all: main.o
main.o: 
	gcc -Wall -g main.c -o main.o
.PHONY: clean all

clean:
	rm -f *.o connections lib*
