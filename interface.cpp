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

void trave(shared_ptr<HuffmanNode> cake, int indent);

int main(){

  //HuffmanNode ob;
  //ob.tableWriter();
//std::cout << "character";
//cout << setw(10) << "This" <<endl;

  HuffmanTree ob("sample.txt");
  ob.buildTree();
  std::unordered_map< char ,string > codeTable;
  ob.mypq.top()->traverse("",codeTable);
  cout<< codeTable.size()<<endl;

  ob.mypq.top()->readCharacters("sample.txt");
  ob.mypq.top()->writeHeaderFile(codeTable);
  /*for(int i = 0; i < ob.characters.size(); i++){
    cout<<ob.characters[i]<<endl;
  }*/

  /*for(auto it: codeTable){
    cout <<it.first<<" " << it.second <<endl;
  }*/


  //ob.mypq.top()->readOutputFile();
  //cout<< codeTable->size();
  //ob.mypq.top()->readCharacters("sample.txt");
  //ob.mypq.top()->writeHeaderFile();
  //object.setSize(size);
  //ob.mypq.top()->traverse("");
  //ob.buildTree();

  /*int count = 0;
  for(auto it: ob.frequencyMap){
    count+=it.second;
  }
  cout <<count<<endl;*/
  /*shared_ptr<HuffmanNode> root(make_shared<HuffmanNode>());
  root = ob.mypq.top();
  cout << "got here"<<endl;*/
  //ob.mypq.top(), 0);
  string code;
  //mypq.top()->traverse(code);

  //f(ob.mypq.top() == NULL){ cout << "NULL";}
  //cout << ob.mypq.top()->getLeft()->left->getValue()<< endl;
  //cout << ob.mypq.top()->right->right->right->getKey()<< endl;
  /*while (!ob.mypq.empty()) {
    cout<<ob.mypq.top()->getKey()<< "="<< ob.mypq.top()->getValue()<< endl;
    ob.mypq.pop();
  }*/
  /*cout << ob.mypq.size() <<endl;
  ob.buildTree();
  cout << ob.mypq.size() <<endl;
  cout << ob.mypq.top()->getValue() <<endl;
  cout << ob.mypq.top()->getKey() <<endl;*/


  return 0;
}
