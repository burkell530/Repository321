# Makefile for Lecture 4

# Type 'make' to create all three executables
all: input-c ss-c functions-c

# Type 'make run-all' to create and run all examples
run-all: input ss functions

# Type 'make input' to run the advanced input example
input: input-c
	./input.run
	
# Run 'make input-c' to create the advanced input executable
input-c: advanced_input.cpp
	g++ -Wall -o input.run advanced_input.cpp

# Run 'make ss' to run the stringstream example
ss: ss-c
	./ss.run

# Run 'make ss-c' to create the stringstream executable
ss-c: stringstream.cpp
	g++ -Wall -o ss.run stringstream.cpp
	
# Run 'make functions' to run the functions example
functions: functions-c
	./functions.run
	
# Run 'make functions-c' to create the stringstream executable
functions-c: functions.cpp
	g++ -Wall -o functions.run functions.cpp

# Clean-Up the executables
clean:
	rm *.run