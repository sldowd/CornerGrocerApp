#ifndef INCLUDE_DATAMAP_H
#define INCLUDE_DATAMAP_H

#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;


class DataMap {
    public:
        // Constructor reads file and creates DataMap
        DataMap(const string& fileName);
        // function takes key as input and returns value
        static int const getMapValue(string key);
    private:
        //map<string, int> dataMap;
        // function called by class to create and write a backup data file
        void writeToFile(const map<string, int> dataMap);
        int mapValue;
};

#endif