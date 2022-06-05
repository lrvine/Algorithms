CC=g++
CFLAGS=-c -g -O3 -Wall
SOURCE=main.cc traversal.cc
LDFLAGS=
OBJECTS= $(SOURCE:.cc=.o)

EXECUTABLE= traversal


all:  $(SOURCE) $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@
