CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
LIBS = -lSDL -lSDL_image -lSDL_ttf

all: main

main: main.o
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f main *.o
