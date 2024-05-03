CC = gcc
FLAGS = -Wall -g

TARGETS = division_by_zero out_of_memory stack_overflow

all: $(TARGETS)

.PHONY: all clean

division_by_zero: division_by_zero.o
	$(CC) $(FLAGS) -o $@ $^

out_of_memory: out_of_memory.o
	$(CC) $(FLAGS) -o $@ $^

stack_overflow: stack_overflow.o
	$(CC) $(FLAGS) -o $@ $^

%.o: %.c
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -f *.o *.h.gch $(TARGETS)