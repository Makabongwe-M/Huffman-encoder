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
  HuffmanNode node;
  HuffmanNode node2;
  int c = 0;

  for(auto it : ob.frequencyMap){
    c++;
    if(c == 4){
      node.setKey(it.first);
      node.setValue(it.second);
    }
    if(c == 6){
      node2.setKey(it.first);
      node2.setValue(it.second);
    }
  }
  HuffmanNode parent(&node, &node2);
  parent.setValue(node.getValue() + node2.getValue());
  //cout << parent.value << endl;
  HuffmanNode *temp;
  temp = parent.left;
  cout << parent.hasLeft()<< endl;
  cout << parent.hasRight()<< endl;
  return 0;
}
