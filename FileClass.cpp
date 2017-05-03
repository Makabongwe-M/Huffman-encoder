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
