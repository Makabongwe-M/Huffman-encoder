#include "HuffmanNode.h"
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

//Copy constructor
HuffmanNode::HuffmanNode(const shared_ptr<HuffmanNode> &other) {
   key = other->key;
   Value = other->Value;

   if(other->hasLeft() && !other->hasRight()){
     left = other->left;
   }
   if(other->hasRight() && !other->hasLeft()){
     right = other->right;
   }
   if(other->hasRight() && other->hasLeft()){
     right = other->right;
     left = other-> left;
   }

}

//move constructor
HuffmanNode::HuffmanNode(shared_ptr<HuffmanNode>&& other){
  key = other->key;
  Value = other->Value;

  if(other->hasLeft() && !other->hasRight()){
    left = other->left;
  }
  if(other->hasRight() && !other->hasLeft()){
    right = other->right;
  }
  if(other->hasRight() && other->hasLeft()){
    right = other->right;
    left = other-> left;
  }

  other->key = '\0';
  other->Value = 0;
  other->right = NULL;
  other-> left = NULL;
}

//an assignment operator
HuffmanNode& HuffmanNode::operator=(const shared_ptr<HuffmanNode> & other)
{
    key = other->key;
    Value = other->Value;

    if(other->hasLeft() && !other->hasRight()){
      left = other->left;
    }
    if(other->hasRight() && !other->hasLeft()){
      right = other->right;
    }
    if(other->hasRight() && other->hasLeft()){
      right = other->right;
      left = other-> left;
    }

    return *this;

}

//constructor that creates a HuffmanNode
HuffmanNode::HuffmanNode(char key, int value){
   key = key;
   Value = value;
}

HuffmanNode::HuffmanNode(shared_ptr<HuffmanNode> &node1, shared_ptr<HuffmanNode> &node2){
  left = node1;
  right = node2;
}

//A method that sets the left child of some HuffmanNode
void HuffmanNode::setLeft(shared_ptr<HuffmanNode> &tree){
    left = tree;
}

//A method that sets the right child of some HuffmanNode
void HuffmanNode::setRight(shared_ptr<HuffmanNode> &tree){
    right = tree;
}

//A method that sets the key (character) of a HuffmanNode
void HuffmanNode::setKey(char k){
  key = k;
}

//A method that sets the value (number of occurances in the text file) of a HuffmanNode
void HuffmanNode::setValue(int val){
  Value = val;
}

//returns the key of HuffmanNode
char HuffmanNode::getKey(){
  return key;
}

//returns the frequency of a key of a HuffmanNode
int HuffmanNode::getValue(){
  return Value;
}

//Checks if a HuffmanNode has a left child
bool HuffmanNode::hasLeft(){
  return left!=NULL;
}

//Checks if a HuffmanNode has a right child
bool HuffmanNode::hasRight(){
  return right!=NULL;
}

//returns the left child of the HuffmanNode
shared_ptr<HuffmanNode> HuffmanNode::getLeft(){
  return left;
}

//returns the right child of the HuffmanNode
shared_ptr<HuffmanNode> HuffmanNode::getRight(){
  return right;
}
/*The method traverses down the tree (in order). It returns the character and its corresponding bitstream.
codeTable (unordered_map) is passed in to store the character and its corresponding bitstream.
*/
void HuffmanNode::traverse(string bitstream, std::unordered_map< char ,string >&codeTable, string &OutputFile){
  if(left == NULL && right == NULL){
    tableWriter(key, bitstream, OutputFile);    //Append the character and its bitstream to the output file
    codeTable.insert({key,bitstream});          //insert the character and its bitstream into the codeTable
  }
  if(left!= NULL){
    left->traverse(bitstream + "0", codeTable, OutputFile);
  }
  if(right!= NULL){
    right->traverse(bitstream+"1", codeTable, OutputFile);
  }

}

//Writes the key(character) and its bitstream into the output file
void HuffmanNode::tableWriter(char key, string bitstream, string &OutputFile){
  std::ofstream fileobject;
  fileobject.open(OutputFile+".txt", std::ofstream::out | std::ofstream::app);
  if(key == '\n'){                              //newline character proved to be a special case
    fileobject<< "\\n"<< " "<< bitstream <<endl;
  }else{
  fileobject<<key<<" = "<<bitstream<<endl;}
  fileobject.close();
}

//For te sake of writing the number of different characters int the text file provided
void HuffmanNode::setSize(int size, string &OutputFile){
  std::ofstream fileobject;
  fileobject.open(OutputFile+".txt", std::ofstream::out | std::ofstream::app);
  fileobject <<"Number of different characters: "<<size<<endl;
  fileobject.close();
}

/*Reads the input file, takes each and every character (in the order they were written) and stores them into a vector
"characters"
*/
void HuffmanNode::readCharacters(string filename){
  char ch;
  fstream object(filename+".txt", fstream::in);
  while (object >> noskipws >> ch){
    characters.push_back(ch);
  }
}

/*codeTable has a character and bitstream. The characters vector has all characters in order.
Find the corresponding bitstream for each character and write into a file.*/
void HuffmanNode::writeHeaderFile(std::unordered_map< char ,string > codeTable, string &OutputFile){

  std::ofstream fileobject;
  fileobject.open(OutputFile+".hdr", std::ofstream::out | std::ofstream::app);
  std::unordered_map<char, string>::iterator it;

  for(int i = 0; i < characters.size(); i++){
      it = codeTable.find(characters[i]);
      if(it != codeTable.end()){
        fileobject<<it->second;
      }
  }
  fileobject.close();
}

HuffmanNode::~HuffmanNode() {

}
