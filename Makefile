CC = gcc
SRC = $(wildcard *.c)
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99
BINDIR = ./bin/

route : $(SRC)
	mkdir -p $(BINDIR)
	$(CC) $^ $(CFLAGS) -o $(BINDIR)$@ 
  
clean:
	rm -rf bin/*
