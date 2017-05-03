#include "HuffmanNode.h"
#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <fstream>
#include <typeinfo>
#include <tr1/unordered_map>
using namespace std::tr1;
using namespace std;

HuffmanNode::HuffmanNode(){
  //default constructor
}

HuffmanNode::HuffmanNode(char key, int value){
   Key = key;
   Value = value;
}

HuffmanNode::HuffmanNode(shared_ptr<HuffmanNode> &node1, shared_ptr<HuffmanNode> &node2){
  left = node1;
  right = node2;
}

void HuffmanNode::setLeft(shared_ptr<HuffmanNode> &tree){
    left = tree;
}


void HuffmanNode::setRight(shared_ptr<HuffmanNode> &tree){
    right = tree;
}

void HuffmanNode::setKey(char k){
  Key = k;
}

void HuffmanNode::setValue(int val){
  Value = val;
}

char HuffmanNode::getKey(){
  return Key;
}

int HuffmanNode::getValue(){
  return Value;
}

bool HuffmanNode::hasLeft(){
  return left!=NULL;
}

bool HuffmanNode::hasRight(){
  return right!=NULL;
}


void HuffmanNode::readCharacters(string filename){
  char ch;
  fstream fin(filename.c_str(), fstream::in);

  while (fin >> noskipws >> ch){
    auto find = frequencyMap.find(ch);  //find the search for the character in the map
    //if the character is in the map already, increment its value
    if(find != frequencyMap.end()){
      find -> second++;
    }else{
      frequencyMap.insert({ch, 1});
    }
  }

}
