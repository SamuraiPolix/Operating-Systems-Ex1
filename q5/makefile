CC = gcc

FLAGS = -Wall -g -pg		# -pg to enable profiling information generation

all: max_sub_array_sum

max_sub_array_sum: max_sub_array_sum.o
	$(CC) $(FLAGS) -o $@ $^ 

%.o: %.c
	$(CC) $(FLAGS) -c $^

clean:
	rm -f *.o *.h.ghc max_sub_array_sum *.out