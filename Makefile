all: bin/chess format

bin/chess: build/chess.o build/printF.o build/sp.o build/checkmove.o
	g++ -Wall -Werror  build/chess.o build/printF.o build/sp.o build/checkmove.o -o bin/chess

build/chess.o: src/chess.cpp src/printF.hpp src/sp.hpp
	clang-format -i src/chess.cpp
	g++ -Wall -Werror -I src -c src/chess.cpp -o build/chess.o

build/printF.o: src/printF.cpp
	g++ -Wall -Werror -I src -c src/printF.cpp -o build/printF.o
	
build/sp.o: src/sp.cpp src/checkmove.hpp
	g++ -Wall -Werror -I src -c src/sp.cpp -o build/sp.o
	
build/checkmove.o: src/checkmove.cpp
	g++ -Wall -Werror -I src -c src/checkmove.cpp -o build/checkmove.o

format: src/printF.cpp src/printF.hpp src/sp.cpp src/sp.hpp src/chess.cpp src/checkmove.cpp src/checkmove.hpp

clean:
	rm -rf build/*.o bin/chess bin/*.o *.o
