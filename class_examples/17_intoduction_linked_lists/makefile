# Makefile for Lecture 16
CXX = /usr/bin/g++
CXXFLAGS = -Wall
ONE = insert_into_array
TWO = delete_from_array
THREE = add_space_to_array

# Type 'make' to create the executables
all: ${ONE} ${TWO} ${THREE} 

${ONE}: ${ONE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${TWO}: ${TWO}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${THREE}: ${THREE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
# Clean-Up the executables
clean:
	rm -rf *.run
