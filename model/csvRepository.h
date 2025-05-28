#ifndef CSV_REPOSITORY_H
#define CSV_REPOSITORY_H

#include <string>
#include <fstream>
#include <filesystem>

using namespace std;
using namespace filesystem;

template<typename T>
class CsvRepository {
private:
    T data;

public:
    // 디렉토리 체크
    void checkDirectory(const string& folderPath) {
        try {
            if (!exists(folderPath)) {
                if (create_directories(folderPath)) {  // 🔄 이 부분만 바뀜
                    cout << "디렉토리가 생성되었습니다: " << folderPath << endl;
                } else {
                    cout << "디렉토리 생성 실패: " << folderPath << endl;
                }
            } else {
                cout << "디렉토리가 이미 존재합니다: " << folderPath << endl;
            }
        } catch (const filesystem_error& e) {
            cout << "오류 발생: " << e.what() << endl;
        }
    }

    // 파일 체크
    void checkFile(const string& filename) {
        if (!exists(filename)) {
            ofstream file(filename);
            file.close();
            cout << "파일이 생성되었습니다." << endl;
        } else {
            cout << "파일이 이미 존재합니다." << endl;
        }
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
            cout << "데이터가 추가되었습니다: " << fullPath << endl;
        } else {
            cout << "파일을 열 수 없습니다: " << fullPath << endl;
        }
    }

    void updateCSV(const T& obj) {
        // TODO: 구현
    }

    void loadCSV(T& obj) {
        // TODO: 구현
    }
};

#endif