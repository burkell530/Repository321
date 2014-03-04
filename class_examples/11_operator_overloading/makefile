# Makefile for Lecture 10.1
CXX = /usr/bin/g++
CXXFLAGS = -Wall
ONE = binary_overload
TWO = unary_overload
THREE = member_overload
FOUR = friend_functions

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