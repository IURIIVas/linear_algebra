CC=gcc
CFLAGS=-c -Wall -g
LDFLAGS=
SOURCES=main.c ./src/matrix.c ./src/vector.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=test

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o ./src/*.o $(EXECUTABLE)