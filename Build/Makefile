CC = g++
CARG = -Wall -std=c++17 -I/usr/include/jsoncpp
SRC = ../Source/main.cpp ../Source/parser.cpp ../Source/jsonParser.cpp
OBJ = obj/main.o obj/parser.o obj/jsonParser.o
TAR = bin/task-cli


obj/%.o: ../Source/%.cpp
	@mkdir -p obj
	$(CC) $(CARG) -c $< -o $@

$(TAR): $(OBJ)
	@mkdir -p bin
	$(CC) $(OBJ) -o $(TAR) -ljsoncpp

clean:
	rm -f obj/* bin/*
