
#include "CreateReports.h"
#include "DataMap.h"

using namespace std;

void printAppleLogo();

int main() {
    //variable to hold user input
    string userInput = "";
    
   // instantiate map object
    DataMap frequencyMap("itemSales.txt");

    cout << "DataMap created. Size: " << frequencyMap.getMap().size() << endl;

    while (userInput != "4") {
        printAppleLogo();
        
        cout << "MENU" << endl;
        cout << "*** 1. Search for an item" << endl;
        cout << "*** 2. Print list report" << endl;
        cout << "*** 3. Print histogram report" << endl;
        cout << "*** 4. Exit Application" << endl;
        cout << "Enter your selection:" << endl;

        cin >> userInput;

        cout << "You selected " << userInput << endl;

        if (userInput == "1") {
            string searchItem;
            int itemFrequency;
            cout << "What item would you like to search for?" << endl;
            cin >> searchItem;
            itemFrequency = frequencyMap.getValue(searchItem);
            cout << "Total " << searchItem << " sold: " << itemFrequency << endl;
        } 
        else if (userInput == "2") {
            CreateReports::createListReport(frequencyMap);
        } 
        else if (userInput == "3") {
            CreateReports::createHistogramReport(frequencyMap);
        } 
        else if (userInput == "4") {
            cout << "Exiting application." << endl;
            break;
        } 
        else {
            cout << "Invalid selection" << endl;
        }
    }
    

    return 0;

}

void printAppleLogo() {
    cout << "     ,--./,-. " << endl;
    cout << "    / #      \\" << endl;
    cout << "   |          |" << endl;
    cout << "    \\        /" << endl;
    cout << "     `._,._,' " << endl;
    cout << endl;
    cout << "  Corner Grocer" << endl;
    cout << endl;
}

