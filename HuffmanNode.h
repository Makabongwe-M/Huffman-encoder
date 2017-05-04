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
    shared_ptr<HuffmanNode> getLeft();
    shared_ptr<HuffmanNode> getRight();
    //void traverse(shared_ptr<HuffmanNode> node);
    shared_ptr<HuffmanNode> left;
    shared_ptr<HuffmanNode> right;
  //  shared_ptr<HuffmanNode> root;

  protected:
    int Parent;
    char Key;
    int Value;


};
#endif
