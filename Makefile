DIR_INCLUDE = 	./include
DIR_SRC =	./src
DIR_OBJ =	./obj
DIR_BIN = 	./bin


SRC =		$(wildcard ${DIR_SRC}/*.cpp)
OBJ =		$(patsubst %.cpp,${DIR_OBJ}/%.o,$(notdir ${SRC}))
LIBS =		-lpthread
TARGET =	testThreadPool
BIN_TARGET = 	${DIR_BIN}/${TARGET}


CXX = 		g++
CXXFLAGS =	-g -O2 -Wall -I${DIR_INCLUDE} -std=c++11 


${BIN_TARGET}:${OBJ}
	$(CXX) $(OBJ) -o $@ $(LIBS)


${DIR_OBJ}/%.o:${DIR_SRC}/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 


clean:
	rm -f `find $(DIR_OBJ) -name *.o`
	rm -f $(BIN_TARGET)

