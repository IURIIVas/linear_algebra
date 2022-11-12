CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.c ./src/matrix.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=matrix

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o ./src/*.o $(EXECUTABLE)