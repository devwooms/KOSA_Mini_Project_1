#ifndef PRODUCT_FACTORY_H
#define PRODUCT_FACTORY_H

#include "entity/product/product.h"
#include "entity/product/drink.h"
#include "entity/product/instantMeal.h"
#include "entity/product/tobacoo.h"
#include <memory>
#include <vector>
#include <string>
#include <map>

class ProductFactory {
public:
    // 제품 타입별 생성 메서드
    static unique_ptr<Product> createProduct(int pkId, const string& name, int price, const string& type, const map<string, string>& attributes = {});

    // CSV 데이터로부터 제품 생성
    static unique_ptr<Product> createFromCSV(const vector<string>& data);
};

#endif 