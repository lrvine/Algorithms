CC=g++
CFLAGS=-c -g -Wall
SOURCE=main.cc 
LDFLAGS=
OBJECTS= $(SOURCE:.cc=.o)

EXECUTABLE= mergesort


all:  $(SOURCE) $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm -f *.o $(EXECUTABLE)
