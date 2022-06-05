CC=g++
CFLAGS=-c -g -Wall -std=c++20 -Ofast
SOURCE=mergeSort.cc main.cc
LDFLAGS=
OBJECTS= $(SOURCE:.cc=.o)

EXECUTABLE= mergeSort


all:  $(SOURCE) $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm -f *.o $(EXECUTABLE)
