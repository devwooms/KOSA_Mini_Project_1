#ifndef PRODUCT_CONTROLLER_H
#define PRODUCT_CONTROLLER_H

#include "../model/entity/product/product.h"
#include "../controller/csvController.h"

using namespace std;

class ProductController {
private:
    CsvController<Product> productCsvController;

public:
    ProductController();
    ~ProductController();
    
    // 제품 관리 메서드
    vector<Product> getAll();            // 조회
    bool add(const Product& product);    // 입력
    bool update(const Product& product); // 수정
    bool remove(int pkId);          // 삭제
};
#endif