all: chess

chess: pf.o sp.o chess.o
    g++ chess.cpp pf.cpp sp.cpp -o chess

pf.o: pf.cpp
    g++ -c pf.cpp
sp.o: sp.cpp
    g++ -c sp.cpp
clean:
    rn -rf *.0 chess
