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

  string InputFile = argv[1];
  string OutputFile = argv[2];

  HuffmanTree ob(InputFile);
  ob.queue.top()->OutputFile = OutputFile;
  ob.queue.top()->InputFile = InputFile;
  int size = ob.queue.size();
  ob.buildTree();

  std::unordered_map< char ,string > codeTable;
  ob.queue.top()->setSize(size, OutputFile);
  ob.queue.top()->traverse("",codeTable, OutputFile);

  ob.queue.top()->readCharacters(InputFile);
  ob.queue.top()->writeHeaderFile(codeTable, OutputFile);



  return 0;
}
