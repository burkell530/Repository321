# Makefile for Lecture 7
CXX = /usr/bin/g++
CXXFLAGS = -Wall

# Type 'make' to create the executables
all: simple advanced functions

# Type 'make simple' to run the simple file i/o example
simple: simple_file_io.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	@echo 'Use ./${@}.run to run'
	
# Type 'make advanced' to run the advanced file i/o example
advanced: advanced_file_io.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	@echo 'Use ./${@}.run to run'
	
# Type 'make functions' to run the streams in functions example
functions: streams_in_functions.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	@echo 'Use ./${@}.run to run'
	
# Clean-Up the executables
clean:
	rm -rf *.run
	rm -rf outfile.txt
	cp append.txt.orig append.txt
	rm -rf functions_output.txt
