

#include "FileHandler.h"

using namespace std;

int main() {
    

    map<string, int> frequencyMap = FileHandler::analyzeFileData("itemSales.txt");

    return 0;

}

