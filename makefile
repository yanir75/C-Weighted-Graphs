all: main.o

main.o: 
  gcc -o main.o main.c
  
.PHONY: clean all

clean:
	rm -f *.o connections lib*
