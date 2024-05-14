CC = gcc

FLAGS = -Wall -g		# -fprofile-arcs and -ftest-coverage for gcov
GCOV = -fprofile-arcs -ftest-coverage

INPUTS_FOLDER = test_inputs
OUTPUTS_FOLDER = test_gcov_outputs

C_FILE = dijkstra.c

COVERAGE_EXEC = test_dijkstra

all: dijkstra

# Declare as non-files
.PHONY: all clean coverage

dijkstra: dijkstra.o 
	$(CC) $(FLAGS) -o $@ $^


# Run tests
# The test cases are in the test_inputs folder, and the gcov file outputs are in the test_gcov_outputs folder
# (We move them to the test_gcov_outputs folder and rename after running each test)
# We added "|| true" to the end of the command to avoid the program from stopping when the errors occurs
# By running this we can see the coverage precent raising with every test run.
coverage:
	$(CC) $(GCOV) dijkstra.c -o dijkstra

	./dijkstra < $(INPUTS_FOLDER)/valid_input.txt || true
	gcov dijkstra.c
	mv dijkstra.c.gcov $(OUTPUTS_FOLDER)/valid_input.txt.gcov

	./dijkstra < $(INPUTS_FOLDER)/invalid_input_early_linebreak.txt || true
	gcov dijkstra.c
	mv dijkstra.c.gcov $(OUTPUTS_FOLDER)/invalid_input_early_linebreak.txt.gcov

	./dijkstra < $(INPUTS_FOLDER)/invalid_input_vertices_number.txt || true
	gcov dijkstra.c
	mv dijkstra.c.gcov $(OUTPUTS_FOLDER)/invalid_input_vertices_number.txt.gcov

	./dijkstra < $(INPUTS_FOLDER)/invalid_input_double_space.txt || true
	gcov dijkstra.c
	mv dijkstra.c.gcov $(OUTPUTS_FOLDER)/invalid_input_double_space.txt.gcov

	./dijkstra < $(INPUTS_FOLDER)/invalid_input_negative_weights.txt || true
	gcov dijkstra.c
	mv dijkstra.c.gcov $(OUTPUTS_FOLDER)/invalid_input_negative_weights.txt.gcov

	./dijkstra < $(INPUTS_FOLDER)/invalid_input_non_integer.txt || true
	gcov dijkstra.c
	mv dijkstra.c.gcov $(OUTPUTS_FOLDER)/invalid_input_non_integer.txt.gcov

	./dijkstra < $(INPUTS_FOLDER)/invalid_input_endline_space.txt || true
	gcov dijkstra.c
	mv dijkstra.c.gcov $(OUTPUTS_FOLDER)/invalid_input_endline_space.txt.gcov


# Create object files
%.o: %.c dijkstra.h
	$(CC) $(FLAGS) -c $<

clean:
	rm -f *.o *.h.ghc dijkstra test_dijkstra *.gcno *.c.gcov *.out *.gcda 