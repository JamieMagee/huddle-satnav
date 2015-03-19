CC = gcc
SRC = $(wildcard *.c)
CFLAGS = -std=c99 -Wall -Wextra
BINDIR = ./bin/

route : $(SRC)
	mkdir -p $(BINDIR)
	$(CC) $^ -o $(BINDIR)$@ $(CFLAGS)
  
clean:
	rm -rf bin/*
