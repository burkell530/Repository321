# Makefile for Lab2.cpp
CXX = /usr/bin/g++
MAIN = new_cat
FILE = Lab2.cpp
CXXFLAGS = -Wall

# Type 'make' to create the executable
${MAIN}: ${FILE}
	${CXX} ${CXXFLAGS} $? -o new_cat
	@echo 'Use ./${MAIN} to run'

#type 'style' to check your code style
style: ../../helpful_files/cpplint.py ${FILE} 
	python $< --filter=-runtime/references,-legal/copyright,-readability/streams,-runtime/explicit,-build/header_guard,-build/include ${FILE}

# Clean-Up the executable
clean:
	rm -rf ${MAIN}
	
