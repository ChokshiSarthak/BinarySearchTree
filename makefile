CFLAGS = -g
CC = g++

bst: main.o bst.o
	$(CC) $(CFLAGS) -o bst main.o bst.o

main.o: main.cc
	$(CC) $(CFLAGS) -c main.cc

bst.o: bst.cc
	$(CC) $(CFLAGS) -c bst.cc

clean:
	rm -f core *.o

