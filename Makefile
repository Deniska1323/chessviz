
all: chess.o
	g++ -Wall -g -o chess.o chess.cpp
clean:
	rm -rf *.o chess
