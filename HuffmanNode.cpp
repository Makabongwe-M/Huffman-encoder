#include "HuffmanNode.h"
#include "FileClass.h"
#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <fstream>
#include <typeinfo>
#include <ctype.h>
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

void HuffmanNode::traverse(string bitstream, std::unordered_map< char ,string >&codeTable){
  if(left == NULL && right == NULL){
    tableWriter(Key, bitstream);
    codeTable.insert({Key,bitstream});
  }
  if(left!= NULL){
    left->traverse(bitstream + "0", codeTable);
  }
  if(right!= NULL){
    right->traverse(bitstream+"1", codeTable);
  }
  //readCharacters("sample.txt");
  //writeHeaderFile();
}

void HuffmanNode::tableWriter(char Key, string bitstream ){
  std::ofstream fileobject;
  fileobject.open("output.txt", std::ofstream::out | std::ofstream::app);
  if(Key == '\n'){
    fileobject << "\\n"<< " "<< bitstream <<endl;

  }else{
  fileobject<<Key<< " "<<bitstream<<endl;}
  fileobject.close();
}

void HuffmanNode::setSize(int size){
  std::ofstream fileobject;
  fileobject.open("output.txt", std::ofstream::out | std::ofstream::app);
  fileobject <<size<<endl;
  fileobject.close();
}

void HuffmanNode::readCharacters(string filename){
  char ch;
  fstream fin(filename.c_str(), fstream::in);
  while (fin >> noskipws >> ch){
    characters.push_back(ch);
    //cout << ch <<endl;
  }

}

void HuffmanNode::writeHeaderFile(std::unordered_map< char ,string > codeTable){
  //std::unordered_map<std::char, string>::iterator Find;
  std::ofstream fileobject;
  fileobject.open("bits.hdr", std::ofstream::out | std::ofstream::app);
  std::unordered_map<char, string>::iterator it;

  for(int i = 0; i < characters.size(); i++){
      it = codeTable.find(characters[i]);
      if(it != codeTable.end()){
        fileobject<<it->second;
        cout << characters[i]<< " " << it->second<<endl;
      }
  }
  fileobject.close();
}
