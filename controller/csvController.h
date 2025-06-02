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

    // CSV 헤더 작성
    void writeHeader(ofstream& file, const T& obj) {
        string header = obj.getHeader();
        if (!header.empty()) {
            file << header << endl;
        }
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

    // 파일 체크 및 헤더 추가
    void checkFile(const string& filename, const T& obj) {
        if (!exists(filename)) {
            ofstream file(filename);
            if (file.is_open()) {
                writeHeader(file, obj);
                file.close();
            }
            if (Config::LOG_ENABLED) {
                cout << "파일이 생성되었습니다." << endl;
            }
        } else {
            if (Config::LOG_ENABLED) {
                cout << "파일이 이미 존재합니다." << endl;
            }
            // 파일이 비어있는지 확인
            ifstream checkFile(filename);
            checkFile.seekg(0, ios::end);
            if (checkFile.tellg() == 0) {
                checkFile.close();
                ofstream file(filename);
                writeHeader(file, obj);
                file.close();
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
        checkFile(fullPath, obj);
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
        bool isFirstLine = true;  // 헤더 라인 스킵을 위한 플래그

        while (getline(file, line)) {
            if (isFirstLine) {  // 첫 번째 줄(헤더)은 건너뛰기
                isFirstLine = false;
                continue;
            }
            if (!line.empty()) {  // 빈 줄 무시
                vector<string> data = parseCSVLine(line);
                T newObj;
                if (newObj.parseFromCSV(data)) {  // 각 클래스가 자신의 파싱 로직 구현
                    objects.push_back(newObj);
                }
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
        checkFile(fullPath, obj);
        
        // 파일 크기 확인
        ifstream checkFile(fullPath);
        checkFile.seekg(0, ios::end);
        bool isEmpty = (checkFile.tellg() <= 0);
        checkFile.close();

        // append 모드로 파일 열기
        ofstream file(fullPath, ios::app);
        if (file.is_open()) {
            // 파일이 비어있다면 헤더 추가
            if (isEmpty) {
                writeHeader(file, obj);
            }
            // 데이터 추가 시 새 줄 추가
            else {
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