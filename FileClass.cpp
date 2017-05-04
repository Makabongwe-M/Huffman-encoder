#include "FileClass.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

FileClass::FileClass(){
    //A constructor that does nothing
}
//constructor that takes in a filename
FileClass::FileClass(std::string fname){
    filename = fname;
}

//Method reads out the file (database) and prints the data on the screen
void FileClass::readFile(){

    //std::string Name, Surname, StudentNumber, StudentRecord;
    std::ifstream fileobject(filename.c_str());
    std::string line;
    while(std::getline(fileobject, line)){
        cout << line << endl;
    }
}

//return the line record that matches the given student number
string FileClass::readLine(std::string StudentNumber){

    std::ifstream fileobject(filename.c_str());
    std::string line;
    while(std::getline(fileobject, line)){
        if(line.find(StudentNumber) != std::string::npos){
            return line;
        }
    }
    return "Does not exist";
}

//This method appends to the file
void FileClass::writeToFile(string instance){
    std::ofstream fileobject;
    fileobject.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
    fileobject << instance+"\n";
}

/*HuffmanTree ob("sample.txt");
shared_ptr<HuffmanNode> node (new HuffmanNode);
shared_ptr<HuffmanNode> node2(new HuffmanNode);
shared_ptr<HuffmanNode> node3(new HuffmanNode);
shared_ptr<HuffmanNode> node4(new HuffmanNode);
int c = 0;
std::priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>,  Comp> mypq;

cout << (*node.get()).getKey();

for(auto it : ob.frequencyMap){
  c++;
  if(c == 4){
    node->setKey(it.first);
    node -> setValue(it.second);
    mypq.push(node);
  }
  if(c == 6){
    node2->setKey(it.first);
    node2->setValue(it.second);
    mypq.push(node2);
  }
  if(c == 8){
    node3->setKey(it.first);
    node3->setValue(it.second);
    mypq.push(node3);
  }

  if(c == 10){
    node4->setKey(it.first);
    node4->setValue(it.second);
    mypq.push(node4);
  }
}

while (!mypq.empty()) {
  cout <<" "<< mypq.top()->getValue() << endl;
  mypq.pop();
}



/*shared_ptr<HuffmanNode> parent (new HuffmanNode);
parent->setValue(node->getValue() + node2->getValue());
parent->setLeft(node2);
parent->setRight(node);*/
