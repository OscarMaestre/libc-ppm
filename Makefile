OBJ_DIR=./obj
SRC_DIR=./src
OPTIONS=-std=c++20 -ggdb
LIB_DIR=./lib

all: libppm.a
	ar rcs $(LIB_DIR)/libppm.a $(OBJ_DIR)/ppmfile.o 


libppm.a: ppmfile.o  
ppmfile.o:$(SRC_DIR)/PPMFile.cpp
	g++ -c $(OPTIONS) $(SRC_DIR)/PPMFile.cpp -o $(OBJ_DIR)/ppmfile.o

clean:
	rm $(OBJ_DIR)/*; rm $(LIB_DIR)/*