#include "HuffmanNode.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <typeinfo>
#include <tr1/unordered_map>
using namespace std::tr1;
using namespace std;


int main(){

  HuffmanNode ob;
  ob.readCharacters("sample.txt");
  shared_ptr<HuffmanNode> node (new HuffmanNode);
  shared_ptr<HuffmanNode> node2(new HuffmanNode);
  int c = 0;

  cout << (*node.get()).getKey();

  for(auto it : ob.frequencyMap){
    c++;
    if(c == 4){
      node->setKey(it.first);
      node -> setValue(it.second);
    }
    if(c == 6){
      node2->setKey(it.first);
      node2->setValue(it.second);
    }
  }
  shared_ptr<HuffmanNode> parent (new HuffmanNode);
  parent->setValue(node->getValue() + node2->getValue());
  parent->setLeft(node2);
  parent->setRight(node);

  cout << parent->hasRight()<< endl;
  cout << parent->hasLeft()<< endl;
  cout << parent->left->getValue()<< endl;
  return 0;
}
