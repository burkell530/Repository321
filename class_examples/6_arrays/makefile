# Makefile for Lecture 6
CXX = /usr/bin/g++
CXXFLAGS = -Wall

# Type 'make' to create the executables
all: arrays-c multi-c dynamic-arrays-c dynamic-multi-c

# Type 'make run-all' to create and run all examples
run-all: arrays multi dynamic-arrays dynamic-multi

# Type 'make arrays' to run the arrays example
arrays: arrays-c
	./arrays.run
	
# Run 'make arrays-c' to create the arrays executable
arrays-c: arrays.cpp
	${CXX} ${CXXFLAGS} -o arrays.run $^

# Run 'make multi' to run the multidimensional arrays example
multi: multi-c
	./multi.run

# Run 'make multi-c' to create the multidimensional executable
multi-c: multidimensional_arrays.cpp
	${CXX} ${CXXFLAGS} -o multi.run $^
	
# Type 'make dynamic-arrays' to run the dynamic-arrays example
dynamic-arrays: dynamic-arrays-c
	./dynamic-arrays.run
	
# Run 'make dynamic-arrays-c' to create the dynamic-arrays executable
dynamic-arrays-c: dynamic_arrays.cpp
	${CXX} ${CXXFLAGS} -o dynamic-arrays.run $^
	
# Type 'make dynamic-multi' to run the dynamic-multidimensional example
dynamic-multi: dynamic-multi-c
	./dynamic-multi.run
	
# Run 'make dynamic-multi-c' to create the dynamic-multidimensional executable
dynamic-multi-c: dynamic_multidimensional_arrays.cpp
	${CXX} ${CXXFLAGS} -o dynamic-multi.run $^


# Clean-Up the executables
clean:
	rm *.run
