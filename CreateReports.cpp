#include "CreateReports.h"

using namespace std;

// report to print list with number frequency
void CreateReports::createListReport(const DataMap& dataMap) {
    const auto& map = dataMap.getMap();
    cout << "Map size: " << map.size() << endl;
    if (map.empty()) {
        cout << "The map is empty!" << endl;
        return;
    }
    for (const auto& item : map) {
        cout << item.first << " " << item.second << endl;
    }
}
// report to print list with histogram
void CreateReports::createHistogramReport(const DataMap& dataMap) {
    const auto& map = dataMap.getMap();
    
    if (map.empty()) {
        cout << "The map is empty. No histogram to display." << endl;
        return;
    }

    // Find the longest string to align the output
    size_t maxLength = 0;
    for (const auto& pair : map) {
        maxLength = max(maxLength, pair.first.length());
    }

    // Print the histogram
    for (const auto& pair : map) {
        cout << left << setw(maxLength + 2) << pair.first << " | ";
        
        // Print asterisks equal to the count
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }

        cout << endl;
        
    }
}