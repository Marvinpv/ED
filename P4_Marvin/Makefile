INC = inc
SRC = src
BIN = bin
OBJ = obj

all: $(BIN)/prueba_diccionario $(BIN)/testdiccionario $(BIN)/testguia

$(BIN)/prueba_diccionario : $(OBJ)/prueba_diccionario.o $(INC)/diccionario.h
	g++ -g -o $(BIN)/prueba_diccionario -I$(INC) $(OBJ)/prueba_diccionario.o
	
$(OBJ)/prueba_diccionario.o : $(SRC)/prueba_diccionario.cpp 
	g++ -g -c -o $(OBJ)/prueba_diccionario.o -I$(INC) $(SRC)/prueba_diccionario.cpp
	
$(BIN)/testdiccionario: $(OBJ)/testdiccionario.o $(INC)/diccionario.h
	g++ -g -o $(BIN)/testdiccionario -I$(INC) $(OBJ)/testdiccionario.o

$(OBJ)/testdiccionario.o: $(SRC)/testdiccionario.cpp
	g++ -g -c -o $(OBJ)/testdiccionario.o -I$(INC) $(SRC)/testdiccionario.cpp
	
$(BIN)/testguia: $(OBJ)/testguia.o $(OBJ)/guia_telefonica.o
	g++ -g -o $(BIN)/testguia $(OBJ)/testguia.o $(OBJ)/guia_telefonica.o

$(OBJ)/testguia.o: $(SRC)/testguia.cpp
	g++ -g -c -o $(OBJ)/testguia.o -I$(INC) $(SRC)/testguia.cpp

$(OBJ)/guia_telefonica.o: $(SRC)/guia_telefonica.cpp $(INC)/guia_telefonica.h
	g++ -g -c -o $(OBJ)/guia_telefonica.o -I$(INC) $(SRC)/guia_telefonica.cpp
