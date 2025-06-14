#ifndef CSV_CONTROLLER_H
#define CSV_CONTROLLER_H

#include <string>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <vector>
#include <iostream>
#include "../config.h"

using namespace std;
using namespace filesystem;

template<typename T>
class CsvController {
private:
    vector<string> parseCSVLine(const string& line) {
        vector<string> result;
        stringstream ss(line);
        string item;
        
        while (getline(ss, item, ',')) {
            result.push_back(item);
        }
        return result;
    }

    void checkDirectory(const string& folderPath) {
        try {
            if (!exists(folderPath)) {
                if (create_directories(folderPath)) { 
                    if (Config::LOG_ENABLED) {
                        cout << "디렉토리가 생성되었습니다: " << folderPath << endl;
                    }
                } else {
                    if (Config::LOG_ENABLED) {
                        cout << "디렉토리 생성 실패: " << folderPath << endl;
                    }
                }
            }
        } catch (const filesystem_error& e) {
            if (Config::LOG_ENABLED) {
                cout << "오류 발생: " << e.what() << endl;
            }
        }
    }

    void checkFile(const string& filename) {
        if (!exists(filename)) {
            ofstream file(filename);
            if (file.is_open()) {
                file.close();
                if (Config::LOG_ENABLED) {
                    cout << "파일이 생성되었습니다: " << filename << endl;
                }
            }
        }
    }

public:
    // 파일에서 모든 라인 읽기
    vector<string> readLines(const string& filepath) {
        vector<string> lines;
        checkDirectory(path(filepath).parent_path().string());
        checkFile(filepath);

        ifstream file(filepath);
        if (!file.is_open()) {
            if (Config::LOG_ENABLED) {
                cout << "파일을 열 수 없습니다: " << filepath << endl;
            }
            return lines;
        }

        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                lines.push_back(line);
            }
        }
        file.close();
        return lines;
    }

    // 파일에 여러 라인 쓰기 (덮어쓰기)
    bool writeLines(const string& filepath, const vector<string>& lines) {
        checkDirectory(path(filepath).parent_path().string());
        
        ofstream file(filepath, ios::trunc);
        if (!file.is_open()) {
            if (Config::LOG_ENABLED) {
                cout << "파일을 열 수 없습니다: " << filepath << endl;
            }
            return false;
        }

        for (const auto& line : lines) {
            file << line << "\n";
        }
        file.close();
        return true;
    }

    // 파일에 한 라인 추가
    bool appendLine(const string& filepath, const string& line) {
        checkDirectory(path(filepath).parent_path().string());
        checkFile(filepath);

        ofstream file(filepath, ios::app);
        if (!file.is_open()) {
            if (Config::LOG_ENABLED) {
                cout << "파일을 열 수 없습니다: " << filepath << endl;
            }
            return false;
        }

        file << line << "\n";
        file.close();
        return true;
    }

    // CSV 라인 파싱 (public으로 이동)
    vector<string> parseLine(const string& line) {
        return parseCSVLine(line);
    }
};

#endif