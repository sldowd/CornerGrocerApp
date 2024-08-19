
#include "CreateReports.h"
#include "DataMap.h"

using namespace std;

int main() {
    
   // instantiate map object
    DataMap frequencyMap("itemSales.txt");

    cout << "DataMap created. Size: " << frequencyMap.getMap().size() << endl;

    // testing list report function
    CreateReports::createListReport(frequencyMap);
    
    CreateReports::createHistogramReport(frequencyMap);

    return 0;

}