LIB_DIR=../lib
LIB_FILE=ppm
INCLUDE_DIR=../src

COMPILE_OPTIONS=-L$(LIB_DIR) -l$(LIB_FILE) -I$(INCLUDE_DIR) -ggdb

all: black

black: black.cpp
	g++ -o black black.cpp $(COMPILE_OPTIONS) 

clean:
	rm black; rm *.ppm