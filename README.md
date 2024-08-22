# Corner Grocer Item Sales Reporting Tool

## Overview
The Corner Grocer Item Sales Reporting Tool is a C++ program designed to analyze and report on the daily item sales data for a corner grocery store. The program reads a text file containing a list of purchased items, analyzes the frequency of each item, and provides a user interface to search for individual item sales, generate a list report, and create a histogram report.

## Features
1. **Item Search**: Allows the user to search for a specific item and view the total number of units sold.
2. **List Report**: Generates a report that lists all purchased items and their corresponding sales frequencies.
3. **Histogram Report**: Creates a visual histogram report that displays the sales frequency for each item using an ASCII-based bar chart.

## Installation
1. Ensure you have a C++ compiler installed on your system.
2. Download the source code files: `main.cpp`, `DataMap.h`, `DataMap.cpp`, `CreateReports.h`, and `CreateReports.cpp`.
3. Compile the program by running the following command in your terminal:
   ```
   g++ -o main main.cpp DataMap.cpp CreateReports.cpp
   ```
4. The executable file `CornerGrocerApp` will be generated, which you can then run to start the program.

## Usage
1. Execute the `CornerGrocerApp` program by moving into the directory and entering the command './main in the terminal.
2. The main menu will be displayed, offering the following options:
   - **1. Search for an item**: Prompts the user to enter an item name and displays the total number of units sold for that item.

        <img width="436" alt="search-for-apples" src="https://github.com/user-attachments/assets/85f6416f-3785-4eec-9dda-e75e4ef60672">

   - **2. Print list report**: Generates and displays a list report of all purchased items and their corresponding sales frequencies.
  
       <img width="247" alt="menu-option-2" src="https://github.com/user-attachments/assets/c8f638ee-453d-4148-b3b0-ed23604014c9">  
   
   - **3. Print histogram report**: Creates and displays a histogram report visualizing the sales frequencies of all purchased items.
  
       <img width="219" alt="menu-option-3" src="https://github.com/user-attachments/assets/fd754735-9119-4fd7-8fc3-2cc231a15e9b">  
   
   - **4. Exit Application**: Exits the program.
  
       <img width="448" alt="exit-application" src="https://github.com/user-attachments/assets/3d992216-c58d-46ad-9511-57f41e4bcfcc">

     
3. Select the desired option by entering the corresponding number (1, 2, 3, or 4) and pressing Enter.
4. Follow the on-screen instructions for each option.
5. To exit the program, select option 4 from the main menu.

## File Structure
- `main.cpp`: Contains the main entry point of the program and the user interface logic.
- `DataMap.h`: Defines the `DataMap` class, which is responsible for reading the item sales data from a file and storing the frequency of each item.
- `DataMap.cpp`: Implements the `DataMap` class.
- `CreateReports.h`: Declares the `CreateReports` class, which provides methods to generate the list and histogram reports.
- `CreateReports.cpp`: Implements the `CreateReports` class.

## Dependencies
The program does not have any external dependencies and can be compiled using a standard C++ compiler.

## License
This program is licensed under the [MIT License](LICENSE).

## Contact
If you have any questions or issues, please feel free to contact the developer at [sarah.dowd1@snhu.com](mailto:sarah.dowd1@snhu.com).
