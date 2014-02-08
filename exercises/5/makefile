# Makefile for Exercise 5
CC = /usr/bin/g++
MAIN = exercise_5
FILE = exercise_5.cpp
OPTIONS = -Wall

# Type 'make' to create the executable
${MAIN}: ${FILE}
	${CC} ${OPTIONS} $? -o $@
	@echo 'Use ./${MAIN} to run'

#type 'style' to check your code style
style: ../../helpful_files/cpplint.py ${FILE} 
	python $< --filter=-legal/copyright,-readability/streams,-runtime/explicit,-build/header_guard,-build/include ${FILE}

# Clean-Up the executable
clean:
	rm ${MAIN}