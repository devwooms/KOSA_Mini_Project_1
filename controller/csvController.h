#ifndef CSV_CONTROLLER_H
#define CSV_CONTROLLER_H

#include <string>
#include <vector>
#include <fstream>
#include "../model/User.h"

class CsvController {
private:
    // 파일이름
    std::string filename;
    // 구분자
    const char delimiter;

public:
    // 생성자
    CsvController(const std::string& filename, char delimiter = ',');

    // Create - 새로운 데이터 추가
    bool addRecord(const std::vector<std::string>& record);

    // Read - 데이터 읽기
    std::vector<std::vector<std::string>> readAllRecords();
    std::vector<std::string> readRecord(int lineNumber);

    // Update - 데이터 수정
    bool updateRecord(int lineNumber, const std::vector<std::string>& newRecord);

    // Delete - 데이터 삭제
    bool deleteRecord(int lineNumber);

    // 유틸리티 메서드
    bool isFileExists() const;
    int getRecordCount() const;
    bool ensureFileExists() const;
    bool initializeWithHeaders(const std::vector<std::string>& headers);

private:
    // 내부 헬퍼 메서드
    std::vector<std::string> splitString(const std::string& str) const;
    std::string joinString(const std::vector<std::string>& parts) const;
    bool writeAllRecords(const std::vector<std::vector<std::string>>& records);
};

#endif 