CC = g++
CFLAGS = `-std=c++11 -Wall`

# Where to install
prefix = /usr/local
BINDIR = $(prefix)/bin
BINS = nyc
OBJ = main.o

nyc: $(OBJ)
	$(CC) $(OBJ) -o nyc

main.o: main.cpp
	$(CC) -c $(CFLAGS) main.cpp

install: $(BINS)
	cp nyc $(BINDIR)/nyc

.PHONY : clean
clean:
	rm $(OBJ)
