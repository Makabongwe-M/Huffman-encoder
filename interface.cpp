#include "HuffmanTree.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <queue>
#include <bits/stdc++.h>
#include <typeinfo>
#include <tr1/unordered_map>
using namespace std::tr1;
using namespace std;



int main(){

  HuffmanTree ob("sample.txt");
  ob.buildTree();
  /*int count = 0;
  for(auto it: ob.frequencyMap){
    count+=it.second;
  }
  cout <<count<<endl;*/
  shared_ptr<HuffmanNode> root;
  root = ob.mypq.top();
  cout <<root->getValue()<<endl;
  ob.traverse(root);
  //ob.buildTree();
//  ob.traverse(root);
  /*while (!ob.mypq.empty()) {
    cout<<ob.mypq.top()->getKey()<< "="<< ob.mypq.top()->getValue()<< endl;
    ob.mypq.pop();
  }*/
  /*cout << ob.mypq.size() <<endl;
  ob.buildTree();
  cout << ob.mypq.size() <<endl;
  cout << ob.mypq.top()->getValue() <<endl;
  cout << ob.mypq.top()->getKey() <<endl;*/


  return 0;
}
