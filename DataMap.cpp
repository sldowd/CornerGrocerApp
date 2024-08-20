#include "DataMap.h"

using namespace std;

DataMap::DataMap(const string& fileName) {
    // input filestream
    ifstream inFS;
    // map to hold items and frequency
    map<string, int> dataMap;
    string line;
    string file = fileName;
    // open sales file
    inFS.open(file);

    // verify file was opened successfully else exit 
    if(!inFS.is_open()) {
        cout << "Error: file could not be opened" << endl;
    }

    while (getline(inFS, line)) {
        // Remove any leading/trailing whitespace
        line.erase(0, line.find_first_not_of(" \t\n\r\f\v"));
        line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1);

        // if line is not empty & key does not exist--key is created and count is initialized to 1 
        // if key exists in map count is incremented
        if (!line.empty()) {
            this->dataMap[line]++;
        }
    }

    // DELETE ME -- PRINTS MAP TO TERMINAL 
    // for (const auto& item : dataMap ) {
    //     cout << item.first << " : " << item.second << endl;
    // }

    // close file
    inFS.close();

    // write to file automatically called to back up data
    this->writeToFile(this->dataMap);
    // return map
}

int DataMap::getValue(const string& key) const {
    auto it = this->dataMap.find(key);
    if (it != this->dataMap.end()) {
        return it->second;
    } else {
        // Handle the case where the key is not found
        std::cerr << "Key not found: " << key << std::endl;
        return 0;  // Or any other default value
    }
}

void DataMap::writeToFile(const map<string, int>& dataMap) {
    // initialize out stream and open file to write to
    ofstream outFS;
    outFS.open("frequency.dat");

    // validate file was successfully opened else exit 
    if (!outFS.is_open()) {
        cout << "Error: file could not be opened.";
        return;
    }

    // loop through data and write each city and temp in celsius
    for (const auto& item : dataMap) {
        outFS << item.first << " " << item.second << endl;
        // check for error after writing each line
        if (outFS.fail()) {
            cout << "Error: write to file failed." << endl;
            return;
        }
    }

    // close file
    outFS.close();
}