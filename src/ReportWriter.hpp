#pragma once

#include <fstream>
#include <string>
using namespace std;
// I am grouping the report-saving method in this class so other tools can reuse it.
class ReportWriter
{
private:
    // I am receiving the filename and report text as arguments instead of storing them here.
public:


    // I am declaring the method that writes the supplied text and returns false if the file cannot open.
    bool exportReport(const string& filename, const string& content);
};


