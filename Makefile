CC = gcc
CFLAGS = -Wall -Werror

all: count

first : count.c count.h
	$(CC) $(CFLAGS) count.c -o count

clean:
	rm -rf count
