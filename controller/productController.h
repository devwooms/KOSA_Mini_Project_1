#ifndef PRODUCT_CONTROLLER_H
#define PRODUCT_CONTROLLER_H

#include "../model/entity/product/product.h"
#include "../model/productFactory.h"
#include "../data/csvRepository.h"
#include <memory>
#include <vector>
#include <map>
#include <functional>

using namespace std;

// 제품 속성을 동적으로 처리하기 위한 구조
struct ProductAttributes {
    int pkId;
    string name;
    int price;
    string type;
    map<string, string> specificAttributes;
};

class ProductController {
private:
    CsvRepository<Product> productCsvRepository;
    map<string, function<void(shared_ptr<Product>&, const map<string, string>&)>> attributeSetters;
    void initializeAttributeSetters();

public:
    ProductController();
    ~ProductController() = default;

    shared_ptr<Product> createProduct(int pkId, const string& name, int price, const string& type, const map<string, string>& attributes = {});
    vector<shared_ptr<Product>> getAll();
    void add(shared_ptr<Product>& product);
    void update(shared_ptr<Product>& product);
    void remove(shared_ptr<Product>& product);
    shared_ptr<Product> get(int pkId);
};

#endif