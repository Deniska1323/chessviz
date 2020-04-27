all: bin/chess format

bin/chess: build/chess.o build/pf.o build/sp.o
	g++ -Wall -Werror  build/chess.o build/pf.o build/sp.o -o bin/chess

build/chess.o: src/chess.cpp src/pf.hpp src/sp.hpp
	clang-format -i src/chess.cpp
	g++ -Wall -Werror -I src -c src/chess.cpp -o build/chess.o

build/pf.o: src/pf.cpp
	g++ -Wall -Werror -I src -c src/pf.cpp -o build/pf.o
	
build/sp.o: src/sp.cpp
	g++ -Wall -Werror -I src -c src/sp.cpp -o build/sp.o

format: src/pf.cpp src/pf.hpp src/sp.cpp src/sp.hpp src/chess.cpp

clean:
	rm -rf build/*.o bin/chess bin/*.o *.o

