.PHONY:clean
CXX=g++
OBJ=./build/src/fifteen.o 
SFMLIB= -Ithirdparty/SFMLlib/include -Lthirdparty/SFMLlib/lib
WWFLAGS=-Wall -Werror
STD=-std=c++17
SFM=-lsfml-graphics -lsfml-window -lsfml-system

all:fifteen test

fifteen: $(OBJ)
	g++ $(WWFLAGS) $(OBJ) -o ./bin/fifteen $(SFMIB) $(SFM)

./build/src/fifteen.o: ./src/main.cpp
	g++ $(WWFLAGS) -c ./src/main.cpp -o ./build/src/fifteen.o $(SFMLIB)

fifteen-test: ./build/test/test.o
	g++ $(WWFLAGS) build/test/test.o -o bin/fifteen-test

build/test/test.o: test/test.cpp
	g++ $(WWFLAGS) -c test/test.cpp -o build/test/test.o

clean:
	rm -rf ./build/src/*.o ./build/test/*.o
