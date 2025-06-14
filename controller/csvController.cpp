#include "csvController.h"
#include <sstream>
#include <algorithm>

CSVController::CSVController(const std::string& filename, char delimiter)
    : filename(filename), delimiter(delimiter) {}

// Create operations
bool CSVController::addRecord(const std::vector<std::string>& record) {
    std::ofstream file(filename, std::ios::app);
    if (!file) return false;
    
    file << joinString(record) << std::endl;
    return true;
}

// Read operations
std::vector<std::vector<std::string>> CSVController::readAllRecords() {
    std::vector<std::vector<std::string>> records;
    std::ifstream file(filename);
    if (!file) return records;

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            records.push_back(splitString(line));
        }
    }
    return records;
}

std::vector<std::string> CSVController::readRecord(int lineNumber) {
    std::vector<std::string> record;
    std::ifstream file(filename);
    if (!file) return record;

    std::string line;
    int currentLine = 0;
    while (std::getline(file, line) && currentLine <= lineNumber) {
        if (currentLine == lineNumber) {
            record = splitString(line);
            break;
        }
        currentLine++;
    }
    return record;
}

// Update operations
bool CSVController::updateRecord(int lineNumber, const std::vector<std::string>& newRecord) {
    auto records = readAllRecords();
    if (lineNumber >= records.size()) return false;
    
    records[lineNumber] = newRecord;
    return writeAllRecords(records);
}

// Delete operations
bool CSVController::deleteRecord(int lineNumber) {
    auto records = readAllRecords();
    if (lineNumber >= records.size()) return false;
    
    records.erase(records.begin() + lineNumber);
    return writeAllRecords(records);
}

// Utility methods
bool CSVController::isFileExists() const {
    std::ifstream file(filename);
    return file.good();
}

int CSVController::getRecordCount() const {
    std::ifstream file(filename);
    if (!file) return 0;

    int count = 0;
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) count++;
    }
    return count;
}

bool CSVController::createFile() const {
    std::ofstream file(filename);
    return file.good();
}

// Private helper methods
std::vector<std::string> CSVController::splitString(const std::string& str) const {
    std::vector<std::string> parts;
    std::stringstream ss(str);
    std::string part;
    
    while (std::getline(ss, part, delimiter)) {
        parts.push_back(part);
    }
    return parts;
}

std::string CSVController::joinString(const std::vector<std::string>& parts) const {
    if (parts.empty()) return "";
    
    std::stringstream ss;
    for (size_t i = 0; i < parts.size() - 1; i++) {
        ss << parts[i] << delimiter;
    }
    ss << parts.back();
    return ss.str();
}

bool CSVController::writeAllRecords(const std::vector<std::vector<std::string>>& records) {
    std::ofstream file(filename);
    if (!file) return false;
    
    for (const auto& record : records) {
        file << joinString(record) << std::endl;
    }
    return true;
}