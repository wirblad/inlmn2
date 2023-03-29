PROG=main.exe
CC=gcc
CFLAGS=-g -Wall
DEPS = safeinput.h menu.h listallcards.h addandremove.h remote.h fakescan.h file.h noheap.h
OBJ = main.o safeinput.o menu.o listallcards.o addandremove.o remote.o fakescan.o file.o noheap.o
 
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
 
$(PROG): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)