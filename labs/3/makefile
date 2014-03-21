# Makefile for user_input_handler
CXX = /usr/bin/g++
MAIN = user_input_handler
FILE = user_input_handler.cpp
CXXFLAGS = -Wall

# Type 'make' to create the executable
${MAIN}: ${FILE}
	${CXX} ${CXXFLAGS} $? -o $@
	@echo 'Use ./${MAIN} to run'

#type 'style' to check your code style
style: ../../helpful_files/cpplint.py ${FILE} 
	python $< --filter=-runtime/references,-legal/copyright,-readability/streams,-runtime/explicit,-build/header_guard,-build/include ${FILE}

# Clean-Up the executable
clean:
	rm -rf ${MAIN}
	
