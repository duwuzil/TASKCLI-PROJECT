CC = g++
CARG = -Wall -std=c++17
SRC = Source/*
OBJ = $(SRC:.cpp=.o)
TAR = task-cli

%.o: %.cpp
	$(CC) $(CARG) -c $< -o $@

$(TAR): $(OBJ)
	$(CC) $(CARG) -o $(TAR) $(OBJ)

clean:
	rm -f $(OBJ) $(TAR)
