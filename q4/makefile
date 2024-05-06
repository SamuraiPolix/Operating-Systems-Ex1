CC = gcc

FLAGS = -Wall -g		# -fprofile-arcs and -ftest-coverage for gcov
GCOV = -coverage

all: dijkstra test

# Declare as non-files
.PHONY: all clean

dijkstra: dijkstra.o 
	$(CC) $(FLAGS) -o $@ $^

test: test.o dijkstra.o
	$(CC) $(FLAGS) $(GCOV) -o $@ $^

# Create object files
%.o: %.c dijkstra.h
	$(CC) $(FLAGS) -c $<

clean:
	rm -f *.o *.h.ghc dijkstra test *.gcno *.c.gcov *.out *.gcda 