#include "HuffmanTree.h"
#include "FileClass.h"
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
  ob.mypq.top()->OutputFile = OutputFile;
  ob.mypq.top()->InputFile = InputFile;
  int size = ob.mypq.size();
  ob.buildTree();

  std::unordered_map< char ,string > codeTable;
  ob.mypq.top()->setSize(size, OutputFile);
  ob.mypq.top()->traverse("",codeTable, OutputFile);

  ob.mypq.top()->readCharacters(InputFile);
  ob.mypq.top()->writeHeaderFile(codeTable, OutputFile);



  return 0;
}
