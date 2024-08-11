#ifndef INCLUDE_FILEHANDLER_H
#define INCLUDE_FILEHANDLER_H

#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;


class FileHandler {
    public:
        // function to read file analyze data and pass into map and return map
        static map<string, int> analyzeFileData(const string& fileName);
        // function to write file
        // creates frequency.dat file, loops through map, and writes data to file
        void writeToFile(const map<string, int>);
};

#endif