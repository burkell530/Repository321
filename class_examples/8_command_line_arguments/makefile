# Makefile for Lecture 8
CXX = /usr/bin/g++
CXXFLAGS = -Wall

# Type 'make' to create the executables
all: simple error

# Type 'make simple' to run the simple command line example
simple: simple_arguments.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	@echo 'Use ./${@}.run arg1 arg2 arg3 etc to run'
	
# Type 'make error' to run the handling errors example
error: error_example.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	@echo 'Use ./${@}.run arg1 arg2 arg3 etc to run'
	
# Clean-Up the executables
clean:
	rm -rf *.run