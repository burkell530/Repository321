# Makefile for Exercise 10
CXX = /usr/bin/g++
MAIN = exercise_10
FILE = exercise_10.cpp
CXXFLAGS = -Wall

# Type 'make' to create the executable
${MAIN}: ${FILE} temperature.cpp temperature.h
	${CXX} ${CXXFLAGS} ${FILE} temperature.cpp -o ${MAIN}
	@echo 'Use ./${MAIN} to run'

#type 'style' to check your code style
style: ../../helpful_files/cpplint.py temperature.cpp temperature.h 
	python $< --filter=-runtime/references,-legal/copyright,-readability/streams,-runtime/explicit,-build/header_guard,-build/include temperature.cpp temperature.h

# Clean-Up the executable
clean:
	rm -rf ${MAIN}
	
