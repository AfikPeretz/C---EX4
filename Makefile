CC=gcc
FLAGS= -Wall

all: frequency
frequency: Trie.o
	$(CC) $(FLAGS) -o frequency $^

Trie.o: Trie.c
	$(CC) $(FLAGS) -c $^

.PHONY:clean all

clean:
	rm *.o frequency *.gch
