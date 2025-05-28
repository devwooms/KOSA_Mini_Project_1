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
    T data;

    // CSV 라인을 파싱하여 벡터로 반환
    vector<string> parseCSVLine(const string& line) {
        vector<string> result;
        stringstream ss(line);
        string item;
        
        while (getline(ss, item, ',')) {
            result.push_back(item);
        }
        return result;
    }

public:
    // 디렉토리 체크
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
            } else {
                if (Config::LOG_ENABLED) {
                    cout << "디렉토리가 이미 존재합니다: " << folderPath << endl;
                }
            }
        } catch (const filesystem_error& e) {
            if (Config::LOG_ENABLED) {
                cout << "오류 발생: " << e.what() << endl;
            }
        }
    }

    // 파일 체크
    void checkFile(const string& filename) {
        if (!exists(filename)) {
            ofstream file(filename);
            file.close();
            if (Config::LOG_ENABLED) {
                cout << "파일이 생성되었습니다." << endl;
            }
        } else {
            if (Config::LOG_ENABLED) {
                cout << "파일이 이미 존재합니다." << endl;
            }
        }
    }

    // CSV 로드 및 객체에 데이터 채우기
    vector<T> loadCSV(T& obj) {
        // 이름 및 폴더 경로 설정
        string fullPath = obj.getFolderPath() + "/" + obj.getFilename();
        // 디렉토리 체크
        checkDirectory(obj.getFolderPath());
        // 파일 체크
        checkFile(fullPath);
        // 파일 열기
        ifstream file(fullPath);
        if (!file.is_open()) {
            if (Config::LOG_ENABLED) {
                cout << "파일을 열 수 없습니다: " << fullPath << endl;
            }
            return vector<T>();
        }

        // 파일 읽기
        vector<T> objects;
        string line;

        while (getline(file, line)) {
            vector<string> data = parseCSVLine(line);
            T newObj;
            if (newObj.parseFromCSV(data)) {  // 각 클래스가 자신의 파싱 로직 구현
                objects.push_back(newObj);
            }
        }
        
        file.close();
        if (Config::LOG_ENABLED) {
            cout << "파일을 읽었습니다: " << fullPath << endl;
            cout << "총 " << objects.size() << "개의 데이터를 로드했습니다." << endl;
        }
        return objects;
    }

    // CSV 저장
    void saveCSV(const T& obj) {
        string fullPath = obj.getFolderPath() + "/" + obj.getFilename();
        checkDirectory(obj.getFolderPath());
        checkFile(fullPath);
        
        // append 모드로 파일 열기
        ofstream file(fullPath, ios::app);
        if (file.is_open()) {
            // 파일이 비어있지 않다면 새 줄 추가
            if (file.tellp() != 0) {
                file << "\n";
            }
            file << obj.toCSV();
            file.close();
            if (Config::LOG_ENABLED) {
                cout << "데이터가 추가되었습니다: " << fullPath << endl;
            }
        } else {
            if (Config::LOG_ENABLED) {
                cout << "파일을 열 수 없습니다: " << fullPath << endl;
            }
        }
    }

    void updateCSV(const T& obj) {
        // TODO: 구현
    }
};

#endif