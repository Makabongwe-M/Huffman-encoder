
executable: interface.o HuffmanNode.o
	g++ -std=c++11 interface.o HuffmanNode.o -o executable

interface.o: interface.cpp
	g++ -std=c++11 -c interface.cpp

HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h
	g++ -std=c++11 -c HuffmanNode.cpp

clean:
	rm *.o executable
