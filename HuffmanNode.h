#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <fstream>
#include <tr1/unordered_map>
using namespace std::tr1;
using namespace std;

class HuffmanNode{
  public:
    HuffmanNode();
    HuffmanNode(HuffmanNode *node1, HuffmanNode *node2);
    HuffmanNode(char key,int value);

    void readCharacters(string filename);
    void setLeft(HuffmanNode *tree);
    void setRight(HuffmanNode *tree);
    void setKey(char k);
    void setValue(int val);
    char getKey();
    int getValue();
    bool hasLeft();
    bool hasRight();
    unordered_map< char ,int > frequencyMap;
    HuffmanNode *left;
    HuffmanNode *right;

  protected:
    int parent;
    char key;
    int value;


};
#endif
