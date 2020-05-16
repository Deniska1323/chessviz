all:bin/chess_test    bin/chess format

bin/chess: build/src/main.o build/src/printF.o build/src/sp.o build/src/checkmove.o build/src/checkfite.o 
	gcc -Wall -Werror build/src/main.o build/src/printF.o build/src/sp.o build/src/checkmove.o build/src/checkfite.o -o bin/chess 

bin/chess_test: build/test/main.o build/test/board_test.o build/src/sp.o build/src/printF.o build/src/checkmove.o build/src/checkfite.o   
	gcc -Wall -Werror build/test/main.o build/src/sp.o build/test/board_test.o build/src/printF.o build/src/checkmove.o build/src/checkfite.o -o bin/chess_test


build/test/main.o: test/main.c thirdparty/ctest.h src/printF.h src/sp.h
	gcc -I thirdparty -I src -c test/main.c -o build/test/main.o
	
build/src/main.o: src/main.c src/printF.h src/sp.h src/checkmove.h src/checkfite.h
	gcc -I thirdparty -I src -c src/main.c -o build/src/main.o

build/test/board_test.o: test/board_test.c thirdparty/ctest.h 
	gcc -I thirdparty -I src -c test/board_test.c -o build/test/board_test.o

#build/chess.o: src/chess.c src/printF.h src/sp.h
#	clang-format -i src/chess.c
#	gcc -Wall -Werror -I src -c src/chess.c -o build/chess.o

build/src/printF.o: src/printF.c
	gcc -Wall -Werror -I src -c src/printF.c -o build/src/printF.o
	
build/src/sp.o: src/sp.c src/checkmove.h src/checkfite.h
	gcc -Wall -Werror -I src -c src/sp.c -o build/src/sp.o
	
build/src/checkmove.o: src/checkmove.c
	gcc -Wall -Werror -I src -c src/checkmove.c -o build/src/checkmove.o
	
build/src/checkfite.o: src/checkfite.c
	gcc -Wall -Werror -I src -c src/checkfite.c -o build/src/checkfite.o

format: src/printF.c src/printF.h src/sp.c src/sp.h src/main.c src/checkmove.c src/checkmove.h src/checkfite.c src/checkfite.h
	clang-format -i src/printF.c src/sp.c src/main.c src/checkmove.c src/checkfite.c


clean:
	rm -rf build/src/*.o build/test/*.o bin/chess bin/chess_test
