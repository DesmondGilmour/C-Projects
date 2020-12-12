CC = gcc
Cflags = -Wall -pedantic -std=c99

all: findWords

findWords: findWords.o textEditing.o
	$(CC) $(Cflags) findWords.o textEditing.o -o findWords 

findWords.o: findWords.c
	$(CC) $(Cflags) -c findWords.c -o findWords.o

textEditing.o: textEditing.c
	$(CC) $(Cflags) -c textEditing.c -o textEditing.o

clean:
	rm findWords.o findWords textEditing.o
