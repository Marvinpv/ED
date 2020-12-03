INC = inc
SRC = src
BIN = bin
OBJ = obj

all: $(BIN)/prueba_diccionario

$(BIN)prueba_diccionario : $(OBJ)/prueba_diccionario.o $(INC)/diccionario.h
	g++ -o $(BIN)/prueba_diccionario -I$(INC) $(OBJ)/prueba_diccionario.o
	
$(OBJ)prueba_diccionario.o : $(SRC)prueba_diccionario.cpp 
	g++ -c -o $(OBJ)/prueba_diccionario.o $(SRC)/prueba_diccionario.cpp
