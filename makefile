.PHONY: clean all run_geometry run_testing
FLAGS := -std=c99
FLAG := -std=c11
SRC_DIR := ./src
BIN_DIR := ./bin
OBJ_DIR := ./build
OBJ_TEST_DIR := ./build/test
TEST_DIR := ./test
all: $(BIN_DIR)/geometry $(BIN_DIR)/testing

$(BIN_DIR)/geometry:  $(OBJ_DIR)/main.o  $(OBJ_DIR)/function.o  $(OBJ_DIR)/parser.o
	gcc -Wall -Wextra  $(OBJ_DIR)/main.o  $(OBJ_DIR)/function.o  $(OBJ_DIR)/parser.o -o $(BIN_DIR)/geometry -lm $(FLAGS)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	gcc -Wall -Wextra -c  $(SRC_DIR)/main.c -o  $(OBJ_DIR)/main.o $(FLAGS)

$(OBJ_DIR)/function.o: $(SRC_DIR)/function.c
		gcc -Wall -Wextra -c  $(SRC_DIR)/function.c -o  $(OBJ_DIR)/function.o -lm $(FLAGS)

$(OBJ_DIR)/parser.o: $(SRC_DIR)/parser.c
	gcc -Wall -Wextra -c  $(SRC_DIR)/parser.c -o  $(OBJ_DIR)/parser.o $(FLAGS)

$(BIN_DIR)/testing: $(OBJ_TEST_DIR)/main.o $(OBJ_TEST_DIR)/parser_test.o $(OBJ_TEST_DIR)/function_test.o $(OBJ_DIR)/function.o $(OBJ_DIR)/parser.o
	gcc   $(OBJ_TEST_DIR)/main.o  $(OBJ_TEST_DIR)/function_test.o  $(OBJ_TEST_DIR)/parser_test.o $(OBJ_DIR)/function.o $(OBJ_DIR)/parser.o -o $(BIN_DIR)/testing -lm $(FLAG)

$(OBJ_TEST_DIR)/main.o: $(TEST_DIR)/main.c
	gcc -I thirdparty -I src -c $(TEST_DIR)/main.c -o  $(OBJ_TEST_DIR)/main.o $(FLAG)

$(OBJ_TEST_DIR)/function_test.o: $(TEST_DIR)/function_test.c
	gcc -I thirdparty -I src -c $(TEST_DIR)/function_test.c -o  $(OBJ_TEST_DIR)/function_test.o -lm $(FLAG)

$(OBJ_TEST_DIR)/parser_test.o: $(TEST_DIR)/parser_test.c
	gcc -I thirdparty -I src -c $(TEST_DIR)/parser_test.c -o  $(OBJ_TEST_DIR)/parser_test.o $(FLAG)

clean:
	rm $(OBJ_DIR)/*.o	
	rm $(OBJ_TEST_DIR)/*.o	
	rm $(BIN_DIR)/geometry
	rm $(BIN_DIR)/testing

run_geometry:
	$(BIN_DIR)/geometry

run_testing: 
	$(BIN_DIR)/testing