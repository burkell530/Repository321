# Makefile Example
# Set the Compiler Location
CXX = /usr/bin/g++
# Set the Compiler Options
CXXFLAGS = -Wall

# Create the Executable
main: main.o point.o rectangle.o
	${CXX} ${CXXFLAGS} -o main $^

main.o: main.cpp point.h rectangle.h
	${CXX} ${CXXFLAGS} -c main.cpp

# If you use CXX and CXXFLAGS you can write the shorthand below	
point.o: point.h

rectangle.o: rectangle.h point.h

clean:
	rm -rf *.o main