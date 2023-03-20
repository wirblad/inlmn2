PROG=main.exe
CC=gcc
CFLAGS=-g -Wall
DEPS = safeinput.h menu.h listallcards.h addandremove.h
OBJ = main.o safeinput.o menu.o listallcards.o addandremove.o
 
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
 
$(PROG): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)