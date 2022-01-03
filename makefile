all: graph
graph: libalgo.a
	gcc -L. -Wall -g -o graph main.c -lalgo

algo.o:
	gcc -c -Wall -Werror -fpic algo.c
libalgo.a: algo.o
	ar rcs libalgo.a algo.o
	
.PHONY: clean all

clean:
	rm -f *.o connections lib* graph
