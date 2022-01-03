all: graph
graph:
	gcc -Wall -g main.c -o graph
	
.PHONY: clean all

clean:
	rm -f *.o connections lib*
