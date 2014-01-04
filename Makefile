CXX = g++
SRC = $(wildcard *.cc)
CFLAGS = -w -O3
BINDIR = ./bin/

route : $(SRC)
	mkdir -p $(BINDIR)
	$(CXX) $^ -o $(BINDIR)$@ $(CFLAGS)
  
clean:
	rm -rf bin/*