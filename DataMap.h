#ifndef INCLUDE_DATAMAP_H
#define INCLUDE_DATAMAP_H

#include <iostream>
#include <map>
#include <string>
#include <fstream>

class DataMap {
    public:
        // Constructor reads file and creates DataMap
        DataMap(const std::string& fileName);
        // function takes key as input and returns value
        const std::map<std::string, int>& getMap() const { return dataMap; }
        int getValue(std::string& key);
        size_t size() const { return dataMap.size(); }
        auto begin() const { return dataMap.begin(); }
        auto end() const { return dataMap.end(); }
    private:
        std::map<std::string, int> dataMap;
        // function called by class to create and write a backup data file
        void writeToFile(const std::map<std::string, int>& dataMap);
};

#endif