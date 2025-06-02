#ifndef PRODUCT_CONTROLLER_H
#define PRODUCT_CONTROLLER_H

#include "../model/entity/product/product.h"
#include "../data/csvRepository.h"

using namespace std;

class ProductController {
private:
    CsvRepository<Product> productCsvRepository;

public:
    ProductController();
    ~ProductController();
    
    // 지하은님 따라서 정리해보기
    // 제품 관리 메서드
    // 제품 조회, 입력, 수정, 삭제
    vector<Product> getAll(Product& product)  { return productCsvRepository.getAll(product);};
    void            add(Product& product)     { productCsvRepository.add(product);};
    void            update(Product& product)  { productCsvRepository.update(product);};
    void            remove(Product& product)  { productCsvRepository.remove(product);};

    // 특정 제품 조회   
    Product get(int pkId) { return productCsvRepository.get(pkId); }


};
#endif