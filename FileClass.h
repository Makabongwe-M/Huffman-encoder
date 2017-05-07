#ifndef FILECLASS_H
#define FILECLASS_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class FileClass{

    public:
        std::string Name, Surname, StudentNumber, StudentRecord, filename;
        FileClass();
        FileClass(std::string fname);
        void readFile();
        void writeToFile(char character, string bitstream);
        string readLine(std::string StudentNumber);
    protected:

};
#endif
