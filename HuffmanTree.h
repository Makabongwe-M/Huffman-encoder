#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include "HuffmanNode.h"
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

class Comp{
  public:
  	bool operator ()(shared_ptr<HuffmanNode> lhs, shared_ptr<HuffmanNode> rhs) {
  		return lhs->getValue() > rhs->getValue();
  	}
};

class HuffmanTree{
  public:
    HuffmanTree(string filename);
    void readCharacters(string filename);
    bool buildTree();
    void traverse(shared_ptr<HuffmanNode> node);
    std::unordered_map< char ,int > frequencyMap;
    priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>,  Comp> mypq;
    shared_ptr<HuffmanNode> root;

  protected:


};
#endif
