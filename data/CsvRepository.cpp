#include "CsvRepository.h"

// 디렉토리 생성
bool CsvRepository::checkDirectory(const string& filepath) const {
    auto parentPath = filesystem::path(filepath).parent_path();
    if (!parentPath.empty()) {
        filesystem::create_directories(parentPath);
    }
    return true;
}

// 파일 존재 여부 확인
bool CsvRepository::checkFile(const string& filepath) const {
    return filesystem::exists(filepath);
}

// 파일 읽기
vector<string> CsvRepository::readFile(const string& filepath) const {
    vector<string> lines;
    ifstream file(filepath);
    string line;
    
    while (getline(file, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }
    return lines;
}

// 파일 쓰기
bool CsvRepository::writeFile(const string& filepath, const vector<string>& lines) const {
    checkDirectory(filepath);
    ofstream file(filepath);
    if (!file) return false;
    
    for (const auto& line : lines) {
        file << line << '\n';
    }
    return true;
}

// 파일 추가
bool CsvRepository::appendFile(const string& filepath, const string& line) const {
    checkDirectory(filepath);
    ofstream file(filepath, ios::app);
    if (!file) return false;
    
    file << line << '\n';
    return true;
}

// 파일 삭제
bool CsvRepository::deleteFile(const string& filepath) const {
    return filesystem::remove(filepath);
}

// CSV 라인을 파싱하여 벡터로 변환
vector<string> CsvRepository::csvToVector(const string& csvLine, char delimiter) const {
    vector<string> result;
    stringstream ss(csvLine);
    string item;
    
    while (getline(ss, item, delimiter)) {
        result.push_back(item);
    }
    return result;
}

// 벡터를 CSV 라인으로 변환
string CsvRepository::vectorToCsv(const vector<string>& data, char delimiter) const {
    if (data.empty()) return "";
    
    stringstream ss;
    for (size_t i = 0; i < data.size() - 1; ++i) {
        ss << data[i] << delimiter;
    }
    ss << data.back();
    return ss.str();
}