CC=g++
CFLAGS=-c -g -Wall -std=c++20 -Ofast
SOURCE=dijkstra.cc main.cc
LDFLAGS=
OBJECTS= $(SOURCE:.cc=.o)

EXECUTABLE= dijkstra


all:  $(SOURCE) $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc .o:
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm -f *.o $(EXECUTABLE)
