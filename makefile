CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c src/avl.c
OUT = arvore_avl

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
