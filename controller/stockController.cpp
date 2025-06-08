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

vector<shared_ptr<Stock>> StockController::getAll() {
    vector<shared_ptr<Stock>> result;
    Stock defaultStock;
    vector<string> lines = stockCsvRepository.getAllLines(defaultStock);

    for (const auto& line : lines) {
        vector<string> data = stockCsvRepository.parseLine(line);
        if (data.size() < 5) continue;

        auto stock = make_shared<Stock>();
        if (stock->parseFromCSV(data)) {
            result.push_back(stock);
        }
    }
    return result;
}

void StockController::add(shared_ptr<Stock>& stock) {
    string csvLine = stock->toCSV();
    stockCsvRepository.addLine(*stock, csvLine);
}

void StockController::update(shared_ptr<Stock>& stock) {
    if (!stock) return;

    auto allStocks = getAll();
    bool found = false;

    for (auto& item : allStocks) {
        if (item->getPkId() == stock->getPkId()) {
            item = make_shared<Stock>(*stock);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "업데이트할 상품을 찾지 못했습니다. ID: " << stock->getPkId() << endl;
        return;
    }

    vector<string> updatedLines;
    for (const auto& item : allStocks) {
        updatedLines.push_back(item->toCSV());
    }

    if (stockCsvRepository.updateLines(*stock, updatedLines)) {
        cout << "데이터가 성공적으로 업데이트되었습니다." << endl;
    }
}

void StockController::remove(shared_ptr<Stock>& stock) {
    // stockCsvRepository.remove(stock);
}

shared_ptr<Stock> StockController::get(int pkId) {
    Stock defaultStock;
    vector<string> lines = stockCsvRepository.getAllLines(defaultStock);
    for (const auto& line : lines) {
        vector<string> data = stockCsvRepository.parseLine(line);
        if (data.size() < 5) continue;
        if (stoi(data[0]) == pkId) {
            auto stock = make_shared<Stock>();
            if (stock->parseFromCSV(data)) {
                return stock;
            }
        }
    }
    return nullptr;
}