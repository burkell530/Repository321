# Makefile for Exercise 20
CXX = /usr/bin/g++
MAIN = exercise_21
CPP_FILES = template.cpp
H_FILES = 
CXXFLAGS = -Wall

# Type 'make' to create the executable
${MAIN}: ${MAIN}.cpp ${H_FILES} ${CPP_FILES}
	${CXX} ${CXXFLAGS} ${MAIN}.cpp ${CPP_FILES} -o $@
	@echo 'Use ./${MAIN} to run'

#type 'style' to check your code style
style: ../../helpful_files/cpplint.py ${FILE} 
	python $< --filter=-runtime/references,-legal/copyright,-readability/streams,-runtime/explicit,-build/header_guard,-build/include ${H_FILES} ${CPP_FILES}

# Clean-Up the executable
clean:
	rm -rf ${MAIN}
	
