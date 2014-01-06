CC = gcc
SRC = $(wildcard *.c)
CFLAGS = -w -std=c99
BINDIR = ./bin/

route : $(SRC)
	mkdir -p $(BINDIR)
	$(CC) $^ -o $(BINDIR)$@ $(CFLAGS)
  
clean:
	rm -rf bin/*
