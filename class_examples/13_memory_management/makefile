# Makefile for Lecture 12
CXX = /usr/bin/g++
CXXFLAGS = -Wall
ONE = dynamic_multi_array
TWO = dynamic_objects
THREE = delete
FOUR = more_pointers

# Type 'make' to create the executables
all: ${ONE} ${TWO} ${THREE} ${FOUR}

${ONE}: ${ONE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${TWO}: ${TWO}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${THREE}: ${THREE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
 ${FOUR}: ${FOUR}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^

# Clean-Up the executables
clean:
	rm -rf *.run