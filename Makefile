
all: chess.o
	g++ -Wall -Werror -g -o chess.o chess.cpp
clean:
	rm -rf *.o chess
