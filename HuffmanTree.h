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
#include <vector>
#include <bits/stdc++.h>
using namespace std::tr1;
using namespace std;

class Comp{
  public:
  	bool operator ()(const shared_ptr<HuffmanNode> lhs, const shared_ptr<HuffmanNode> rhs) {
  		return lhs->getValue() > rhs->getValue();
  	}
};

class HuffmanTree{
  public:
    HuffmanTree();
    HuffmanTree(string filename);
    void readCharacters(string filename);
    void setSize(int temp);
    bool buildTree();
    std::unordered_map< char ,int > frequencyMap;
    std::unordered_map< char ,string > codeTable;
    std::vector<char> characters;
    priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>,  Comp> queue;
    shared_ptr<HuffmanNode> root;
    string OutputFile;

  protected:

};
#endif
