#include <iostream>
#include <map>
#include <string>
#include <fstream>

#include "FileHandler.h"

map<string, int> FileHandler::analyzeFileData(const string& fileName) {
    // input filestream
    ifstream inFS;
    // map to hold items and frequency
    map<string, int> frequencyMap;
    string line;
    string file = fileName;
    // open sales file
    inFS.open(file);

    // verify file was opened successfully else exit 
    if(!inFS.is_open()) {
        cout << "Error: file could not be opened" << endl;
        return map<string, int>();
    }
    

    while (getline(inFS, line)) {
        // Remove any leading/trailing whitespace
        line.erase(0, line.find_first_not_of(" \t\n\r\f\v"));
        line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1);

        // if line is not empty & key does not exist--key is created and count is initialized to 1 
        // if key exists in map count is incremented
        if (!line.empty()) {
            frequencyMap[line]++;
        }
    }

    // DELETE ME -- PRINTS MAP TO TERMINAL 
    for (const auto& item : frequencyMap ) {
        cout << item.first << " : " << item.second << endl;
    }

    // close file and return data map
    inFS.close();
    return frequencyMap;
}

void FileHandler::writeToFile(const map<string, int> frequencyMap) {
    // initialize out stream and open file to write to
    ofstream outFS;
    outFS.open("frequency.dat");

    // validate file was successfully opened else exit 
    if (!outFS.is_open()) {
        cout << "Error: file could not be opened.";
        return;
    }

    // loop through data and write each city and temp in celsius
    for (const auto& item : frequencyMap) {
        outFS << item.first << " : " << item.second << endl;
        // check for error after writing each line
        if (outFS.fail()) {
            cout << "Error: write to file failed." << endl;
            return;
        }
    }

    // close file
    outFS.close();
}