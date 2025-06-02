#ifndef CSV_REPOSITORY_H
#define CSV_REPOSITORY_H

#include "../controller/csvController.h"
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

template<typename T>
class CsvRepository {
private:
    CsvController<T> csvController;

public:
    CsvRepository() = default;
    ~CsvRepository() = default;

    // 조회
    vector<T> getAll(T& obj){         
        return csvController.loadCSV(obj); 
    };

    // 입력
    void add(T& obj){                 
        csvController.saveCSV(obj);
    };

    // 수정
    void update(T& obj){              
        // 1. 모든 제품을 로드
        vector<T> data = getAll(obj);
        
        // 2. 해당 제품을 찾아서 업데이트
        auto it = find_if(data.begin(), data.end(),
            [&obj](const T& item) { return item.getPkId() == obj.getPkId(); });
        
        if (it == data.end()) {
            cout << "업데이트할 제품을 찾지 못했습니다." << endl;
            return;
        }
        
        // 제품 정보 업데이트
        *it = obj;
        
        // 3. 전체 목록을 다시 저장
        string fullPath = obj.getFolderPath() + "/" + obj.getFilename();
        ofstream file(fullPath, ios::trunc);  // 파일을 새로 생성
        if (!file.is_open()) {
            cout << "파일을 열 수 없습니다." << endl;
            return;
        }
        
        // 모든 제품을 다시 저장
        for (size_t i = 0; i < data.size(); ++i) {
            file << data[i].toCSV();
            if (i < data.size() - 1) {
                file << "\n";
            }
        }
        
        file.close();
        cout << "제품 정보가 업데이트되었습니다." << endl;
    };

    // 삭제
    void remove(T& obj){                 
        // 1. 모든 제품을 로드
        vector<T> data = getAll(obj);
        
        // 2. 해당 제품을 찾아서 제거
        // find_if 조건에 맞는 첫 번째 요소를 찾아주는 함수
        auto it = find_if(data.begin(), data.end(),
            [&obj](const T& item) { return item.getPkId() == obj.getPkId(); });
        
        if (it == data.end()) {
            cout << "제품을 찾지 못했습니다." << endl;
            return;  // 제품을 찾지 못함
        }
        
        data.erase(it);
        
        // 3. 전체 목록을 다시 저장
        string fullPath = obj.getFolderPath() + "/" + obj.getFilename();
        ofstream file(fullPath, ios::trunc);  // 파일을 새로 생성
        if (!file.is_open()) {
            return;
        }
        
        // 모든 제품을 다시 저장
        for (size_t i = 0; i < data.size(); ++i) {
            file << data[i].toCSV();
            if (i < data.size() - 1) {
                file << "\n";
            }
        }
        
        file.close();
    };

    // 특정 제품 조회
    T get(int pkId){
        T obj;
        vector<T> data = getAll(obj);
        auto it = find_if(data.begin(), data.end(),
            [&pkId](const T& item) { return item.getPkId() == pkId; });
        
        if (it != data.end()) {
            return *it;  // 찾은 객체 반환
        }
        return T();  // 찾지 못한 경우 기본 객체 반환
    }


};
#endif