#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
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
    HuffmanNode(const shared_ptr<HuffmanNode> &other);
    HuffmanNode(shared_ptr<HuffmanNode>&& other);
    HuffmanNode& operator=(const shared_ptr<HuffmanNode>& other);
    HuffmanNode& operator=(shared_ptr<HuffmanNode>&& other)=delete;;
    HuffmanNode(shared_ptr<HuffmanNode> &node1, shared_ptr<HuffmanNode> &node2);
    HuffmanNode(char key,int value);
    ~HuffmanNode();


    void setLeft(shared_ptr<HuffmanNode> &tree);
    void setRight(shared_ptr<HuffmanNode> &tree);
    void setKey(char k);
    void setValue(int val);
    char getKey();
    int getValue();
    bool hasLeft();
    bool hasRight();
    void tableWriter(char key, string bitstream, string &outputFile);
    void readCharacters(string filename);
    void writeHeaderFile(std::unordered_map< char ,string > codeTable, string &outputFile);
    shared_ptr<HuffmanNode> getLeft();
    shared_ptr<HuffmanNode> getRight();
    void traverse(string bitstream, std::unordered_map< char ,string >&codeTable, string &outputFile);
    shared_ptr<HuffmanNode> left;
    shared_ptr<HuffmanNode> right;
    std::vector<char> characters;
    string outputFile;
    string inputFile;
    void setSize(int size, string &outputFile);


  protected:
    int size;
    int parent;
    char key;
    int value;



};
#endif
