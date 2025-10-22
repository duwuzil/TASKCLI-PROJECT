CC = g++
CARG = -Wall -std=c++17

SRC = ../Source/main.cpp
OBJ = obj/main.o
TAR = bin/task-cli

obj/%.o: ../Source/%.cpp
	@mkdir -p obj
	$(CC) $(CARG) -c $< -o $@

$(TAR): $(OBJ)
	@mkdir -p bin
	$(CC) $(CARG) -o $(TAR) $(OBJ)

clean:
	rm -f obj/* bin/*
