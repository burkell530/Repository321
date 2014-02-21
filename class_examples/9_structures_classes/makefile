# Makefile for Lecture 9
CXX = /usr/bin/g++
CXXFLAGS = -Wall
ONE = structures
TWO = structure_concepts
THREE = class
FOUR = member_functions
FIVE = parameters_return
SIX = encapsulation
SEVEN = accessor_mutator

# Type 'make' to create the executables
all: ${ONE} ${TWO} ${THREE} ${FOUR} ${FIVE} ${SIX} ${SEVEN}

${ONE}: ${ONE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${TWO}: ${TWO}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${THREE}: ${THREE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^

${FOUR}: ${FOUR}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^

${FIVE}: ${FIVE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${SIX}: ${SIX}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${SEVEN}: ${SEVEN}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^

# Clean-Up the executables
clean:
	rm -rf *.run