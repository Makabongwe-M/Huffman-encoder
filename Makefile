CXX = g++ -std=c++11
CFLAG = -c

executable: interface.o HuffmanNode.o
	$(CXX) interface.o HuffmanNode.o -o executable

interface.o: interface.cpp
	$(CXX) $(CFLAG) interface.cpp

HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h
	$(CXX) $(CFLAG) HuffmanNode.cpp

clean:
	rm *.o executable
