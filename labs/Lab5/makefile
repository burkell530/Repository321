# Makefile for lab 5
CXX = /usr/bin/g++
MAIN = lab_5_unit_test
CPP_FILES = dl_node.cpp dl_list.cpp 
H_FILES = dl_node.h dl_list.h
CXXFLAGS = -Wall -g

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