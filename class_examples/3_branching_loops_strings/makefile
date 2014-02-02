# Makefile for Lecture 3

# Type 'make' to create all three executables
all: branching-c loops-c sc-c

# Type 'make run-all' to create and run all examples
run-all: branching loops sc

# Type 'make branching' to run the branching example
branching: branching-c
	./branching.run
	
# Run 'make branching-c' to create the branching executable
branching-c:
	g++ -Wall -o branching.run branching.cpp

# Run 'make loops' to run the loops example
loops: loops-c
	./loops.run

# Run 'make loops-c' to create the loops executable
loops-c:
	g++ -Wall -o loops.run loops.cpp
	
# Run 'make sc' to run the string/character example
sc: sc-c
	./string_character.run
	
# Run 'make sc' to create the string_branching executable
sc-c:
	g++ -Wall -o string_character.run string_character.cpp

# Clean-Up the executables
clean:
	rm *.run