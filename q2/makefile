CC = gcc

FLAGS = -Wall -g

all: Poisson

Poisson: poisson.o
	$(CC) $(FLAGS) -o $@ $^ -lm

%.o: %.c
	$(CC) $(FLAGS) -c $^

clean:
	rm -f *.o *.h.ghc Poisson