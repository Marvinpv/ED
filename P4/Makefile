INC = inc
SRC = src
BIN = bin
OBJ = obj

all: $(BIN)/prueba_diccionario $(BIN)/testdiccionario

$(BIN)/prueba_diccionario : $(OBJ)/prueba_diccionario.o $(INC)/diccionario.h
	g++ -o $(BIN)/prueba_diccionario -I$(INC) $(OBJ)/prueba_diccionario.o
	
$(OBJ)/prueba_diccionario.o : $(SRC)/prueba_diccionario.cpp 
	g++ -c -o $(OBJ)/prueba_diccionario.o -I$(INC) $(SRC)/prueba_diccionario.cpp
	
$(BIN)/testdiccionario: $(OBJ)/testdiccionario.o $(INC)/diccionario.h
	g++ -o $(BIN)/testdiccionario -I$(INC) $(OBJ)/testdiccionario.o

$(OBJ)/testdiccionario.o: $(SRC)/testdiccionario.cpp
	g++ -c -o $(OBJ)/testdiccionario.o -I$(INC) $(SRC)/testdiccionario.cpp
