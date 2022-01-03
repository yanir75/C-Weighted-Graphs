all: graph
graph: libalgo.a 
	gcc -static -Wall -g main.c -L. -lalgo -o graph
Algorithms.o: 
	gcc -static -g -Wall -c Algorithms.c
libalgo.a: Algorithms.o
	ar -rcs libalgo.a Algorithms.o

.PHONY: clean all

clean:
	rm -f *.o connections lib*
