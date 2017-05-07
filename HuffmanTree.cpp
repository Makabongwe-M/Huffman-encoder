#include "HuffmanTree.h"
#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <fstream>
#include <typeinfo>
#include <tr1/unordered_map>
using namespace std::tr1;
using namespace std;

HuffmanTree::HuffmanTree(){

}

HuffmanTree::HuffmanTree(string filename){
  readCharacters(filename);
  for(auto it: frequencyMap){
    shared_ptr<HuffmanNode> node(make_shared<HuffmanNode>());
    node->setKey(it.first);
    node->setValue(it.second);
    mypq.push(node);
  }

}

void HuffmanTree::readCharacters(string filename){
  char ch;
  fstream fin(filename+".txt", fstream::in);

  while (fin >> noskipws >> ch){
    auto find = frequencyMap.find(ch);  //find the search for the character in the map
    characters.push_back(ch);
    //if the character is in the map already, increment its value
    if(find != frequencyMap.end()){
      find -> second++;
    }else{
      frequencyMap.insert({ch, 1});
    }
  }
}
bool HuffmanTree::buildTree(){

  while(mypq.size() > 1){
    shared_ptr<HuffmanNode> node1;
    node1 = mypq.top();
    mypq.pop();
    shared_ptr<HuffmanNode> node2;
    node2 = mypq.top();
    mypq.pop();

    shared_ptr<HuffmanNode> parent(make_shared<HuffmanNode>());
    parent->setValue(node1->getValue() + node2->getValue());
    parent->setLeft(node1);
    parent->setRight(node2);
    mypq.push(parent);

  }
  return false;
}
