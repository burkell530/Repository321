# Makefile for Exercise 11
CXX = /usr/bin/g++
MAIN = exercise_11
FILE = exercise_11.cpp
CXXFLAGS = -Wall

# Type 'make' to create the executable
${MAIN}: ${FILE} money.cpp money.h
	${CXX} ${CXXFLAGS} ${FILE} money.cpp -o ${MAIN}
	@echo 'Use ./${MAIN} to run'

#type 'style' to check your code style
style: ../../helpful_files/cpplint.py money.cpp money.h 
	python $< --filter=-runtime/references,-legal/copyright,-readability/streams,-runtime/explicit,-build/header_guard,-build/include money.cpp money.h

# Clean-Up the executable
clean:
	rm -rf ${MAIN}
	
