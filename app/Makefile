CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD 
EXEC = biquadris
OBJECTS = main.o display.o player.o block.o i-block.o j-block.o l-block.o o-block.o s-block.o t-block.o z-block.o single_block.o square.o level.o level_0.o level_1.o level_2.o level_3.o level_4.o board.o simpleboard.o decorator.o blind.o force.o heavy.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
