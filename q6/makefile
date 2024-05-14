CC = gcc

FLAGS = -Wall -g

all: add2PB findPhone

.PHONY: all clean

add2PB: add2PB.c
	$(CC) $(FLAGS) $< -o $@

findPhone: findPhone.c
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -f add2PB findPhone
