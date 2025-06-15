#ifndef CSV_REPOSITORY_H
#define CSV_REPOSITORY_H

#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class CsvRepository
{
   public:
    // 파일 존재 여부 확인
    bool checkFile(const string& filepath) const;

    // 파일 읽기
    vector<string> readFile(const string& filepath) const;
    // 파일 쓰기
    bool writeFile(const string& filepath, const vector<string>& lines) const;
    // 파일 추가
    bool appendFile(const string& filepath, const string& line) const;
    // 파일 삭제
    bool deleteFile(const string& filepath) const;

    // CSV 라인을 파싱하여 벡터로 변환
    vector<string> csvToVector(const string& csvLine, char delimiter = ',') const;
    // 벡터를 CSV 라인으로 변환
    string vectorToCsv(const vector<string>& data, char delimiter = ',') const;
};

#endif