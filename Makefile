all: chess

chess: printF.o sp.o chess.o
	g++ chess.cpp printF.cpp sp.cpp -o chess

printF.o: printF.cpp
	g++ -c printF.cpp
sp.o: sp.cpp
	g++ -c sp.cpp
clean:
	rn -rf *.0 chess
