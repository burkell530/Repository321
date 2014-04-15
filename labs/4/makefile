# Makefile for Lab 4
CXX = /usr/bin/g++
CXXFLAGS = -Wall

MAIN_LUKE = unit_test
MAIN_UI = ui_test

CPP_LUKE = todo_item.cpp todo_list.cpp CinReader.cpp
H_LUKE = todo_item.h todo_list.h CinReader.h

CPP_UI = ${CPP_LUKE} todo_ui.cpp driver.cpp
H_UI = ${H_LUKE} todo_ui.h driver.cpp

ALL_STYLECHECK_FILES = ${CPP_UI} ${H_UI}

# Type 'make' to create the executable
${MAIN_LUKE}: ${MAIN_LUKE}.cpp ${H_LUKE} ${CPP_LUKE}
	${CXX} ${CXXFLAGS} ${MAIN_LUKE}.cpp ${CPP_LUKE} -o $@
	@echo 'Use ./${MAIN_LUKE} to run'

${MAIN_UI}: ${H_UI} ${CPP_UI}
	${CXX} ${CXXFLAGS} ${CPP_UI} -o $@
	@echo 'Use ./${MAIN_UI} to run'

#type 'style' to check your code style
style: ../../helpful_files/cpplint.py ${FILE} 
	python $< --filter=-runtime/references,-legal/copyright,-readability/streams,-runtime/explicit,-build/header_guard,-build/include ${ALL_STYLECHECK_FILES}

# Clean-Up the executable
clean:
	rm -rf ${MAIN_LUKE}
	
