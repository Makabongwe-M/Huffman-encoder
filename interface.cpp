#include "HuffmanTree.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctype.h>
#include <fstream>
#include <queue>
#include <bits/stdc++.h>
#include <typeinfo>
#include <iomanip>
#include <tr1/unordered_map>
using namespace std::tr1;
using namespace std;
using std::cout;
using std::setw;


int main(int argc, char *argv[]){

  string inputFile = argv[1];
  string outputFile = argv[2];

  HuffmanTree ob(inputFile);
  ob.queue.top()->outputFile = outputFile;
  ob.queue.top()->inputFile = inputFile;
  int size = ob.queue.size();
  ob.buildTree();

  std::unordered_map< char ,string > codeTable;
  ob.queue.top()->setSize(size, outputFile);
  ob.queue.top()->traverse("",codeTable, outputFile);

  ob.queue.top()->readCharacters(inputFile);
  ob.queue.top()->writeHeaderFile(codeTable, outputFile);



  return 0;
}
