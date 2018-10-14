CXX = g++
CXXFLAGS = -std=c++14 -Wall -g -MMD
OBJECTS = main.o graph.o neuron.o math.o util.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = main

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean
clean:
	rm *.o *.d *.stackdump