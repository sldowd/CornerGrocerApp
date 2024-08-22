// This file Contains the main entry point of the program and the user interface logic.

// Library needed for toTitleCase();
#include <cctype>

// Include Class definitions
#include "CreateReports.h"
#include "DataMap.h"

using namespace std;

// Declaraion of functions defined below main()
void printAppleLogo();
string toTitleCase(string searchItem);

int main() {
    string userInput;

    // Instantiate DataMap object
    DataMap frequencyMap("itemSales.txt");

    // Print menu for user to interact with
    while (true) {
        printAppleLogo();
        cout << "MENU" << endl;
        cout << "*** 1. Search for an item" << endl;
        cout << "*** 2. Print list report" << endl;
        cout << "*** 3. Print histogram report" << endl;
        cout << "*** 4. Exit Application" << endl;
        cout << "Enter your selection: ";

        // Error handling while reading user input with getline to avoid issues with non-string input
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
        
        // Item search returns frequency, includes error handling for empty input
        if (userInput == "1") {
            string searchItem;
            cout << "What item would you like to search for? ";
            if (!getline(cin, searchItem) || searchItem.empty()) {
                cout << "Error reading item input. Please try again." << endl;
                continue;
            }

            // Calls DataMap member getValue to return item frequency and outputs result
            // Search item passed into toTitleCase function before search
            int itemFrequency = frequencyMap.getValue(toTitleCase(searchItem));
            cout << "Total " << searchItem << " sold: " << itemFrequency << endl;
        }
        // Map of key : value pairs of sale items and their frequency sold is output as list
        else if (userInput == "2") {
            CreateReports::createListReport(frequencyMap);
        }
        // Map of key : value pairs of sale items and their frequency sold is output in histogram form
        else if (userInput == "3") {
            CreateReports::createHistogramReport(frequencyMap);
        }
        // Inout of "4" exits the application
        else if (userInput == "4") {
            cout << "Exiting application." << endl;
            break;
        }
    }

    return 0;
}

// ASCII apple with store name to print at the top of the menu -- could easily be replaced with different item
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

// Function to convert search item to title case to prevent lower case search item from return false results
// Additional functionality to handle all caps could be added
string toTitleCase(string searchItem) {
    // Isolate first character from string
    char firstChar = searchItem[0];
    // Convert that character to upper case
    char upperChar = toupper(firstChar);

    // Assign uppercase character to first index of string
    searchItem[0] = upperChar;
    // Return title case searchItem to pass into search
    return searchItem;

}
