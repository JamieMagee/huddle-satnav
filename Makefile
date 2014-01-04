CXX = g++
SRC = $(wildcard *.cc)
CFLAGS = -w
BINDIR = ./bin/

route : $(SRC)
	mkdir -p $(BINDIR)
	$(CXX) $^ -o $(BINDIR)$@ $(CFLAGS)
  
clean:
	rm -rf bin/*
