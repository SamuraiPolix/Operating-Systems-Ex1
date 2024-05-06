CC = gcc

FLAGS = -Wall -g

LIB_POISSON_D = libpoisson.so

MAIN_OBJECT = poisson.o 

all: Poisson

# Declare as non-files
.PHONY: all clean

Poisson: $(MAIN_OBJECT) $(LIB_POISSON_D)
	$(CC) $(FLAGS) -o $@ $< ./$(LIB_POISSON_D) -lm

# Create object files
%.o: %.c
	$(CC) $(FLAGS) -c $^

# Create libraries
$(LIB_POISSON_D): libpoisson.o
	$(CC) $(FLAGS) -shared $^ -o $@

clean:
	rm -f *.o *.h.ghc Poisson *.so