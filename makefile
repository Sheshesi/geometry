.PHONY: clean all run_geometry run_testing
SRC_DIR := ./src
BIN_DIR := ./bin
OBJ_DIR := ./build
all: $(BIN_DIR)/geometry.exe

$(BIN_DIR)/geometry.exe:  $(OBJ_DIR)/main.o  $(OBJ_DIR)/print.o  $(OBJ_DIR)/inputCheck.o  $(OBJ_DIR)/check.o
	gcc -Wall -Wextra  $(OBJ_DIR)/main.o  $(OBJ_DIR)/print.o  $(OBJ_DIR)/inputCheck.o $(OBJ_DIR)/check.o -o $(BIN_DIR)/geometry.exe -lm

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	gcc -Wall -Wextra -c  $(SRC_DIR)/main.c -o  $(OBJ_DIR)/main.o 

$(OBJ_DIR)/print.o: $(SRC_DIR)/print.c
		gcc -Wall -Wextra -c  $(SRC_DIR)/print.c -o  $(OBJ_DIR)/print.o -lm

$(OBJ_DIR)/inputCheck.o: $(SRC_DIR)/inputCheck.c
	gcc -Wall -Wextra -c  $(SRC_DIR)/inputCheck.c -o  $(OBJ_DIR)/inputCheck.o

$(OBJ_DIR)/check.o: $(SRC_DIR)/check.c
	gcc -Wall -Wextra -c  $(SRC_DIR)/check.c -o  $(OBJ_DIR)/check.o

clean:
	rm $(OBJ_DIR)/*.o	
	rm $(OBJ_TEST_DIR)/*.o	
	rm $(BIN_DIR)/geometry.exe

run_geometry:
	$(BIN_DIR)/geometry.exe
