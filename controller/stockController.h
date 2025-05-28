#ifndef STOCK_CONTROLLER_H
#define STOCK_CONTROLLER_H

#include "../model/entity/stock/stock.h"
#include "../controller/csvController.h"

using namespace std;

class StockController {
private:
    CsvController<Stock> stockCsvController;

public:
    StockController();
    ~StockController();
    
    // 재고 관리 메서드
    vector<Stock> getAll();            // 재고 조회
    bool add(const Stock& stock);      // 재고 추가
    bool update(const Stock& stock);   // 재고 수정
    bool remove(int productId);        // 재고 삭제
    
    // 재고 특화 메서드
    bool updateQuantity(int productId, int quantity);  // 재고 수량 변경
    bool checkExpiration(int productId);              // 유통기한 확인
};

#endif 