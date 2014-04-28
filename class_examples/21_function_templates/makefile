# Makefile for Lecture 21
CXX = /usr/bin/g++
CXXFLAGS = -Wall
ONE = four_max
TWO = templated_max

# Type 'make' to create the executables
all: ${ONE} ${TWO}

${ONE}: ${ONE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${TWO}: ${TWO}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
# Clean-Up the executables
clean:
	rm -rf *.run
