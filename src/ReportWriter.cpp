#include "ReportWriter.hpp"
#include <iostream>

using namespace std;
bool ReportWriter::exportReport(const string& filename, const string& content) {
    // I am opening the output file, creating it if needed or replacing its existing contents.
    ofstream file(filename);

    // I am checking that the file opened before attempting to write the report.
        if(!file.is_open()){
            cerr << "File didn't open";
            return false;
        }

    // I am writing the supplied report text and closing the file afterward.
        file << content;
    file.close();

    // I am reporting success based on the earlier file-open check.
    return true;
}
