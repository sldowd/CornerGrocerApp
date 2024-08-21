
#include <cctype>

#include "CreateReports.h"
#include "DataMap.h"

using namespace std;

void printAppleLogo();
string toTitleCase(string searchItem);

int main() {
    string userInput;

    // Instantiate DataMap object
    DataMap frequencyMap("itemSales.txt");

    while (true) {
        printAppleLogo();
        cout << "MENU" << endl;
        cout << "*** 1. Search for an item" << endl;
        cout << "*** 2. Print list report" << endl;
        cout << "*** 3. Print histogram report" << endl;
        cout << "*** 4. Exit Application" << endl;
        cout << "Enter your selection: ";

        // Use getline to avoid issues with non-string input
        if (!getline(cin, userInput)) {
            cout << "Error reading input. Please try again." << endl;
            continue;
        }

        // Validate menu selection
        if (userInput == "1" || userInput == "2" || userInput == "3" || userInput == "4") {
            cout << "You selected " << userInput << endl;
        } else {
            cout << "Invalid selection. Please try again." << endl;
            continue;
        }

        if (userInput == "1") {
            string searchItem;
            cout << "What item would you like to search for? ";
            if (!getline(cin, searchItem) || searchItem.empty()) {
                cout << "Error reading item input. Please try again." << endl;
                continue;
            }

            int itemFrequency = frequencyMap.getValue(toTitleCase(searchItem));
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

// function to convert search item to title case 
string toTitleCase(string searchItem) {
    // isolate first character from string
    char firstChar = searchItem[0];
    // convert that character to upper case
    char upperChar = toupper(firstChar);

    // assign uppercase character to first index of string
    searchItem[0] = upperChar;
    // return title case searchItem to pass into search
    return searchItem;

}
