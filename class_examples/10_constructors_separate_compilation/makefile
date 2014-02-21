# Makefile for Lecture 10
CXX = /usr/bin/g++
CXXFLAGS = -Wall
ONE = constructor
TWO = initial_overload
THREE = separate_compilation
FOUR = default_arguments
FIVE = overloading_concepts
#SIX = encapsulation
#SEVEN = accessor_mutator

# Type 'make' to create the executables
all: ${ONE} ${TWO} ${THREE} ${FOUR} ${FIVE} #${SIX} ${SEVEN}

${ONE}: ${ONE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${TWO}: ${TWO}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${THREE}: ${THREE}.cpp my_class.cpp my_class.h
	${CXX} ${CXXFLAGS} -o ${@}.run ${THREE}.cpp my_class.cpp

${FOUR}: ${FOUR}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^

${FIVE}: ${FIVE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
#${SIX}: ${SIX}.cpp
#	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
#${SEVEN}: ${SEVEN}.cpp
#	${CXX} ${CXXFLAGS} -o ${@}.run $^

# Clean-Up the executables
clean:
	rm -rf *.run