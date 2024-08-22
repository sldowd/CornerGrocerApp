// Defines the `CreateReports` class, which provides methods
// to generate the list and histogram reports.

#ifndef CREATEREPORTS_H
#define CREATEREPORTS_H

// libraries
#include <map>
#include <string>
#include <iostream>
#include <iomanip>

#include "DataMap.h"



class CreateReports {
    public:
        // report to print list with number frequency
        static void createListReport(const DataMap& dataMap);
        // report to print list with histogram
        static void createHistogramReport(const DataMap& dataMap);
};


#endif