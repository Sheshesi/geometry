FLAGS := -std=c99
FLAG := -std=c11
SRC_DIR := ./src
BIN_DIR := ./bin
OBJ_DIR := ./build
OBJ_TEST_DIR := ./build/test
TEST_DIR := ./test
.PHONY: clean install uninstall all run

all: $(BIN_DIR)/function $(BIN_DIR)/testing


$(BIN_DIR)/function:  $(OBJ_DIR)/main.o  $(OBJ_DIR)/function.o  $(OBJ_DIR)/parser.o
	gcc -Wall -Wextra  $(OBJ_DIR)/main.o  $(OBJ_DIR)/function.o  $(OBJ_DIR)/parser.o -o $(BIN_DIR)/function -lm $(FLAGS)


$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	gcc -Wall -Wextra -c  $(SRC_DIR)/main.c -o  $(OBJ_DIR)/main.o $(FLAGS)


$(OBJ_DIR)/function.o: $(SRC_DIR)/function.c
		gcc -Wall -Wextra -c  $(SRC_DIR)/function.c -o  $(OBJ_DIR)/function.o -lm $(FLAGS)


$(OBJ_DIR)/parser.o: $(SRC_DIR)/parser.c
	gcc -Wall -Wextra -c  $(SRC_DIR)/parser.c -o  $(OBJ_DIR)/parser.o $(FLAGS)

#gcc ./test/*.c ./src/function.c -lm -std=c11

$(BIN_DIR)/testing: $(OBJ_TEST_DIR)/main.o $(OBJ_TEST_DIR)/parser.o $(OBJ_TEST_DIR)/function.o $(OBJ_DIR)/function.o
	gcc $(OBJ_TEST_DIR)/main.o  $(OBJ_TEST_DIR)/function.o  $(OBJ_TEST_DIR)/parser.o $(OBJ_DIR)/function.o -o $(BIN_DIR)/testing -lm $(FLAG)


$(OBJ_TEST_DIR)/main.o: $(TEST_DIR)/main.c
	gcc -c $(TEST_DIR)/main.c -o  $(OBJ_TEST_DIR)/main.o $(FLAG)


$(OBJ_TEST_DIR)/function.o: $(TEST_DIR)/function.c
	gcc -c $(TEST_DIR)/function.c -o  $(OBJ_TEST_DIR)/function.o -lm $(FLAG)


$(OBJ_TEST_DIR)/parser.o: $(TEST_DIR)/parser.c
	gcc -c $(TEST_DIR)/parser.c -o  $(OBJ_TEST_DIR)/parser.o $(FLAG)

clean:
	find -name "*.o" -exec rm -rf {} +
	rm -rf ./bin/function


run: all
	$(BIN_DIR)/function
	$(BIN_DIR)/testing

install:
	sudo cp ./bin/function /usr/bin/function

uninstall:
	sudo rm -f /usr/bin/function
