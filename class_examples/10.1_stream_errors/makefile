# Makefile for Lecture 10.1
CXX = /usr/bin/g++
CXXFLAGS = -Wall
ONE = stream_errors
TWO = type_min_max

# Type 'make' to create the executables
all: ${ONE} ${TWO}

${ONE}: ${ONE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${TWO}: ${TWO}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^

# Clean-Up the executables
clean:
	rm -rf *.run