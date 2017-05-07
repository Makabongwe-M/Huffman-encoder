CXX = g++ -std=c++11
CFLAG = -c

executable: interface.o HuffmanNode.o HuffmanTree.o FileClass.o
	$(CXX) interface.o HuffmanNode.o HuffmanTree.o FileClass.o -o executable

interface.o: interface.cpp
	$(CXX) $(CFLAG) interface.cpp

HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h
	$(CXX) $(CFLAG) HuffmanNode.cpp

HuffmanTree.o: HuffmanTree.cpp HuffmanTree.h
	$(CXX) $(CFLAG) HuffmanTree.cpp

FileClass.o: FileClass.cpp FileClass.h
	$(CXX) $(CFLAG) FileClass.cpp

clean:
	rm *.o executable
