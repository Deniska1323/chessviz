all:bin/chess_test    bin/chess format 

bin/chess_test: build/main.o build/board_test.o build/sp.o build/printF.o build/checkmove.o build/checkfite.o   
	gcc -Wall -Werror build/main.o build/sp.o build/board_test.o build/printF.o build/checkmove.o build/checkfite.o   -o bin/chess_test


build/main.o: test/main.c thirdparty/ctest.h
	gcc -I thirdparty -I src -c test/main.c -o build/main.o

build/board_test.o: test/board_test.c thirdparty/ctest.h 
	gcc -I thirdparty -I src -c test/board_test.c -o build/board_test.o

bin/chess: build/chess.o build/printF.o build/sp.o build/checkmove.o build/checkfite.o 
	gcc -Wall -Werror  build/chess.o build/printF.o build/sp.o build/checkmove.o build/checkfite.o -o bin/chess

build/chess.o: src/chess.c src/printF.h src/sp.h
	clang-format -i src/chess.c
	gcc -Wall -Werror -I src -c src/chess.c -o build/chess.o

build/printF.o: src/printF.c
	gcc -Wall -Werror -I src -c src/printF.c -o build/printF.o
	
build/sp.o: src/sp.c src/checkmove.h src/checkfite.h
	gcc -Wall -Werror -I src -c src/sp.c -o build/sp.o
	
build/checkmove.o: src/checkmove.c
	gcc -Wall -Werror -I src -c src/checkmove.c -o build/checkmove.o
	
build/checkfite.o: src/checkfite.c
	gcc -Wall -Werror -I src -c src/checkfite.c -o build/checkfite.o

format: src/printF.c src/printF.h src/sp.c src/sp.h src/chess.c src/checkmove.c src/checkmove.h src/checkfite.c src/checkfite.h
	clang-format -i src/printF.c src/sp.c src/chess.c src/checkmove.c src/checkfite.c


clean:
	rm -rf build/*.o bin/chess bin/*.o *.o

