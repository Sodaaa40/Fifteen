.PHONY:clean
CXX=g++
OBJ=./build/src/fifteen.o 
SFMLIB= -Ithirdparty/SFMLlib/include -Lthirdparty/SFMLlib/lib
WWFLAGS=-Wall -Werror
STD=-std=c++17
SFM=-lsfml-graphics -lsfml-window -lsfml-system

all:fifteen

fifteen: $(OBJ)
	g++ $(WWFLAGS) $(OBJ) -o ./bin/fifteen $(SFMIB) $(SFM)

./build/src/fifteen.o: ./src/main.cpp
	g++ $(WWFLAGS) -c ./src/main.cpp -o ./build/src/fifteen.o $(SFMLIB)

clean:
	rm -rf ./build/src/*.o ./build/test/*.o
