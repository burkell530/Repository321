# Makefile for Exercise 22
CXX = /usr/bin/g++
MAIN = exercise_22
CPP_FILES = 
H_FILES = 
CXXFLAGS = -Wall

# Type 'make' to create the executable
${MAIN}: ${MAIN}.cpp ${H_FILES} ${CPP_FILES}
	${CXX} ${CXXFLAGS} ${MAIN}.cpp ${CPP_FILES} -o $@
	@echo 'Use ./${MAIN} to run'

#type 'style' to check your code style
style: ../../helpful_files/cpplint.py ${FILE} 
	python $< --filter=-runtime/references,-legal/copyright,-readability/streams,-runtime/explicit,-build/header_guard,-build/include exercise_22.cpp

# Clean-Up the executable
clean:
	rm -rf ${MAIN}
	
