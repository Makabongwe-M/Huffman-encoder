#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include "FileClass.h"
#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <fstream>
#include <tr1/unordered_map>
#include <queue>
#include <bits/stdc++.h>
using namespace std::tr1;
using namespace std;

class HuffmanNode{
  public:
    HuffmanNode();
    HuffmanNode(shared_ptr<HuffmanNode> &node1, shared_ptr<HuffmanNode> &node2);
    HuffmanNode(char key,int value);

    void setLeft(shared_ptr<HuffmanNode> &tree);
    void setRight(shared_ptr<HuffmanNode> &tree);
    void setKey(char k);
    void setValue(int val);
    char getKey();
    int getValue();
    bool hasLeft();
    bool hasRight();
    void tableWriter(char Key, string bitstream);
    void readCharacters(string filename);
    void writeHeaderFile(std::unordered_map< char ,string > codeTable);
    shared_ptr<HuffmanNode> getLeft();
    shared_ptr<HuffmanNode> getRight();
    void traverse(string bitstream, std::unordered_map< char ,string >&codeTable);
    shared_ptr<HuffmanNode> left;
    shared_ptr<HuffmanNode> right;
    //std::unordered_map< char ,string > codeTable;
    //string traverse(shared_ptr<HuffmanNode> root,string bitstream);
    std::vector<char> characters;
    
    //std::unordered_map< char ,string > codeTable;
    void setSize(int size);
    string OutputFile;
    string InputFile;
    //FileClass ob("output.txt");
  //  shared_ptr<HuffmanNode> root;

  protected:
    int size;
    int Parent;
    char Key;
    int Value;


};
#endif
