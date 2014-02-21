# Makefile for Lecture 9.1
CXX = /usr/bin/g++
CXXFLAGS = -Wall
ONE = formatting

# Type 'make' to create the executables
all: ${ONE}

${ONE}: ${ONE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^

# Clean-Up the executables
clean:
	rm -rf *.run