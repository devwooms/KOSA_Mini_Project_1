#ifndef STOCK_CONTROLLER_H
#define STOCK_CONTROLLER_H

#include "../model/entity/stock/stock.h"
#include "../data/csvRepository.h"

using namespace std;

class StockController {
private:
    // CsvRepository<Stock> stockCsvRepository;

public:
    StockController();
    ~StockController();
    
    // 지하은님 따라서 정리해보기
    // 재고 관리 메서드
    // 재고 조회, 입력, 수정, 삭제
    // vector<shared_ptr<Stock>>   getAll(Stock& stock)  { return stockCsvRepository.getAll(stock);};
    // void            add(Stock& stock)     { stockCsvRepository.add(stock);};
    // void            update(Stock& stock)  { stockCsvRepository.update(stock);};
    // void            remove(Stock& stock)  { stockCsvRepository.remove(stock);};
    
};

#endif 