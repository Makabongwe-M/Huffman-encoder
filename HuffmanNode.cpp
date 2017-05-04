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

shared_ptr<HuffmanNode> HuffmanNode::getLeft(){
  return left;
}
shared_ptr<HuffmanNode> HuffmanNode::getRight(){
  return right;
}

/*void HuffmanNode::traverse(shared_ptr<HuffmanNode> node){
  if(root == NULL){return;}
  cout << root->getLeft()->getValue();
  cout << root->getValue() << endl;
  CodeTable(root->getRight());

}*/
