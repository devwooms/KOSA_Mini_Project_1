#include "stockController.h"
#include <iostream>
#include <ctime>

using namespace std;

StockController::StockController() {
    // 생성자 구현
}

StockController::~StockController() {
    // 소멸자 구현
}

vector<Stock> StockController::getAll() {
    Stock stock;
    return stockCsvController.loadCSV(stock);
}

bool StockController::add(const Stock& stock) {
    stockCsvController.saveCSV(stock);
    return true;
}

bool StockController::update(const Stock& stock) {
    // 1. 모든 재고를 로드
    Stock temp;
    vector<Stock> stocks = stockCsvController.loadCSV(temp);
    
    // 2. 해당 재고를 찾아서 업데이트
    auto it = find_if(stocks.begin(), stocks.end(),
        [&stock](const Stock& s) { return s.getProduct().getPkId() == stock.getProduct().getPkId(); });
    
    if (it == stocks.end()) {
        cout << "업데이트할 재고를 찾지 못했습니다." << endl;
        return false;
    }
    
    // 재고 정보 업데이트
    *it = stock;
    
    // 3. 전체 목록을 다시 저장
    string fullPath = temp.getFolderPath() + "/" + temp.getFilename();
    ofstream file(fullPath, ios::trunc);
    if (!file.is_open()) {
        cout << "파일을 열 수 없습니다." << endl;
        return false;
    }
    
    // 모든 재고를 다시 저장
    for (size_t i = 0; i < stocks.size(); ++i) {
        file << stocks[i].toCSV();
        if (i < stocks.size() - 1) {
            file << "\n";
        }
    }
    
    file.close();
    cout << "재고 정보가 업데이트되었습니다." << endl;
    return true;
}

bool StockController::remove(int productId) {
    // 1. 모든 재고를 로드
    Stock temp;
    vector<Stock> stocks = stockCsvController.loadCSV(temp);
    
    // 2. 해당 재고를 찾아서 제거
    auto it = find_if(stocks.begin(), stocks.end(),
        [productId](const Stock& s) { return s.getProduct().getPkId() == productId; });
    
    if (it == stocks.end()) {
        cout << "삭제할 재고를 찾지 못했습니다." << endl;
        return false;
    }
    
    stocks.erase(it);
    
    // 3. 전체 목록을 다시 저장
    string fullPath = temp.getFolderPath() + "/" + temp.getFilename();
    ofstream file(fullPath, ios::trunc);
    if (!file.is_open()) {
        cout << "파일을 열 수 없습니다." << endl;
        return false;
    }
    
    // 모든 재고를 다시 저장
    for (size_t i = 0; i < stocks.size(); ++i) {
        file << stocks[i].toCSV();
        if (i < stocks.size() - 1) {
            file << "\n";
        }
    }
    
    file.close();
    return true;
}

bool StockController::updateQuantity(int productId, int quantity) {
    // 1. 모든 재고를 로드
    Stock temp;
    vector<Stock> stocks = stockCsvController.loadCSV(temp);
    
    // 2. 해당 재고를 찾아서 수량 업데이트
    auto it = find_if(stocks.begin(), stocks.end(),
        [productId](const Stock& s) { return s.getProduct().getPkId() == productId; });
    
    if (it == stocks.end()) {
        cout << "수량을 변경할 재고를 찾지 못했습니다." << endl;
        return false;
    }
    
    it->setQuantity(quantity);
    
    // 3. 전체 목록을 다시 저장
    string fullPath = temp.getFolderPath() + "/" + temp.getFilename();
    ofstream file(fullPath, ios::trunc);
    if (!file.is_open()) {
        cout << "파일을 열 수 없습니다." << endl;
        return false;
    }
    
    // 모든 재고를 다시 저장
    for (size_t i = 0; i < stocks.size(); ++i) {
        file << stocks[i].toCSV();
        if (i < stocks.size() - 1) {
            file << "\n";
        }
    }
    
    file.close();
    cout << "재고 수량이 업데이트되었습니다." << endl;
    return true;
}

bool StockController::checkExpiration(int productId) {
    // 1. 모든 재고를 로드
    Stock temp;
    vector<Stock> stocks = stockCsvController.loadCSV(temp);
    
    // 2. 해당 재고를 찾아서 유통기한 확인
    auto it = find_if(stocks.begin(), stocks.end(),
        [productId](const Stock& s) { return s.getProduct().getPkId() == productId; });
    
    if (it == stocks.end()) {
        cout << "유통기한을 확인할 재고를 찾지 못했습니다." << endl;
        return false;
    }
    
    // 현재 날짜와 유통기한 비교
    time_t now = time(0);
    tm* ltm = localtime(&now);
    
    // TODO: 유통기한 문자열을 날짜로 변환하여 비교하는 로직 구현
    cout << "유통기한: " << it->getExpirationDate() << endl;
    return true;
} 