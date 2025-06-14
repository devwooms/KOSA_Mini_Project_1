#ifndef CSV_REPOSITORY_H
#define CSV_REPOSITORY_H

#include "../controller/csvController.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>

using namespace std;

template<typename T>
class CsvRepository {
private:
    CsvController<T> csvController;

    string getFilePath(const T& obj) const {
        return obj.getFolderPath() + "/" + obj.getFilename();
    }

public:
    vector<string> getAllLines(const T& obj) {
        string filepath = getFilePath(obj);
        return csvController.readLines(filepath);
    }

    bool addLine(const T& obj, const string& line) {
        string filepath = getFilePath(obj);
        return csvController.appendLine(filepath, line);
    }

    bool updateLines(const T& obj, const vector<string>& lines) {
        string filepath = getFilePath(obj);
        return csvController.writeLines(filepath, lines);
    }

    vector<string> parseLine(const string& line) {
        return csvController.parseLine(line);
    }
};
#endif