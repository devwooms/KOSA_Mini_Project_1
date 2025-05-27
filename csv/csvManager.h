#ifndef CSV_MANAGER_H
#define CSV_MANAGER_H

#include <string>

using namespace std;

class CsvManager {
private:
    // string filename;
    // string keyword;
    // string folderPath;

public:
    void checkDirectory(string folderPath);
    void checkFile(string filename);
    void saveCSV();
    void updateCSV();
    void loadCSV();

};

#endif