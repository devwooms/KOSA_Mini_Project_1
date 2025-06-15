#include "CsvController.h"
#include <sstream>
#include <algorithm>
#include <filesystem>

CsvController::CsvController(const std::string& filename, char delimiter)
    : filename(filename), delimiter(delimiter) {
    // 파일 경로에서 디렉토리 부분 추출
    std::filesystem::path filePath(filename);
    auto parentPath = filePath.parent_path();
    
    // 디렉토리가 없으면 생성
    if (!parentPath.empty()) {
        std::filesystem::create_directories(parentPath);
    }
    
    // 파일이 없으면 생성
    if (!isFileExists()) {
        ensureFileExists();
    }
}

// Create operations
bool CsvController::addRecord(const std::vector<std::string>& record) {
    std::ofstream file(filename, std::ios::app);
    if (!file) return false;
    
    file << joinString(record) << std::endl;
    return true;
}

// Read operations
std::vector<std::vector<std::string>> CsvController::readAllRecords() {
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

std::vector<std::string> CsvController::readRecord(int lineNumber) {
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
bool CsvController::updateRecord(int lineNumber, const std::vector<std::string>& newRecord) {
    auto records = readAllRecords();
    if (lineNumber >= records.size()) return false;
    
    records[lineNumber] = newRecord;
    return writeAllRecords(records);
}

// Delete operations
bool CsvController::deleteRecord(int lineNumber) {
    auto records = readAllRecords();
    if (lineNumber >= records.size()) return false;
    
    records.erase(records.begin() + lineNumber);
    return writeAllRecords(records);
}

// Utility methods
bool CsvController::isFileExists() const {
    std::ifstream file(filename);
    return file.good();
}

int CsvController::getRecordCount() const {
    std::ifstream file(filename);
    if (!file) return 0;

    int count = 0;
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) count++;
    }
    return count;
}

bool CsvController::ensureFileExists() const {
    std::ofstream file(filename);
    return file.good();
}

bool CsvController::initializeWithHeaders(const std::vector<std::string>& headers) {
    if (!isFileExists() || getRecordCount() == 0) {
        std::ofstream file(filename);
        if (!file) return false;
        file << joinString(headers) << std::endl;
        return true;
    }
    return false;
}

// Private helper methods
std::vector<std::string> CsvController::splitString(const std::string& str) const {
    std::vector<std::string> parts;
    std::stringstream ss(str);
    std::string part;
    
    while (std::getline(ss, part, delimiter)) {
        parts.push_back(part);
    }
    return parts;
}

std::string CsvController::joinString(const std::vector<std::string>& parts) const {
    if (parts.empty()) return "";
    
    std::stringstream ss;
    for (size_t i = 0; i < parts.size() - 1; i++) {
        ss << parts[i] << delimiter;
    }
    ss << parts.back();
    return ss.str();
}

bool CsvController::writeAllRecords(const std::vector<std::vector<std::string>>& records) {
    std::ofstream file(filename);
    if (!file) return false;
    
    for (const auto& record : records) {
        file << joinString(record) << std::endl;
    }
    return true;
}