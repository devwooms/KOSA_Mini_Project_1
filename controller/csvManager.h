#ifndef CSV_MANAGER_H
#define CSV_MANAGER_H

#include <string>
#include <fstream>
#include <filesystem>

using namespace std;
using namespace filesystem;

template<typename T>
class CsvManager {
private:
    T data;

public:
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

    void checkFile(const string& filename) {
        if (!exists(filename)) {
            ofstream file(filename);
            file.close();
            cout << "파일이 생성되었습니다." << endl;
        } else {
            cout << "파일이 이미 존재합니다." << endl;
        }
    }

    void saveCSV(const T& obj) {
        checkDirectory(obj.getFolderPath());
        checkFile(obj.getFilename());
        string fullPath = obj.getFolderPath() + "/" + obj.getFilename();
        checkFile(fullPath);
        ofstream file(fullPath);
        file << obj.toString();
        file.close();
    }

    void updateCSV(const T& obj) {
        // TODO: 구현
    }

    void loadCSV(T& obj) {
        // TODO: 구현
    }
};

#endif