#include "productController.h"
#include <iostream>
#include <algorithm>

productController::productController() {
    product tempProduct;
    std::string filepath = tempProduct.getFolderPath() + "/" + tempProduct.getFilename();
    csvCtrl = std::make_shared<csvController>(filepath);
    
    // 헤더가 없으면 초기화
    if (csvCtrl->getRecordCount() == 0) {
        csvCtrl->initializeWithHeaders({"ID", "ProductID", "Name", "Price", "Category"});
    }
}

bool productController::addProduct(const product& prod) {
    std::vector<std::string> record = {
        std::to_string(getNextId()),
        prod.getProductID(),
        prod.getName(),
        std::to_string(prod.getPrice()),
        prod.getCategory()
    };
    
    return csvCtrl->addRecord(record);
}

std::vector<product> productController::getAllProducts() {
    std::vector<product> products;
    auto records = csvCtrl->readAllRecords();
    
    // 첫 번째 행이 헤더인 경우 건너뛰기
    for (size_t i = 1; i < records.size(); ++i) {
        product prod;
        if (prod.parseFromCSV(records[i])) {
            products.push_back(prod);
        }
    }
    
    return products;
}

std::shared_ptr<product> productController::getProductById(int id) {
    auto products = getAllProducts();
    auto it = std::find_if(products.begin(), products.end(),
                          [id](const product& p) { return p.getId() == id; });
    
    if (it != products.end()) {
        return std::make_shared<product>(*it);
    }
    return nullptr;
}

std::shared_ptr<product> productController::getProductByName(const std::string& name) {
    auto products = getAllProducts();
    auto it = std::find_if(products.begin(), products.end(),
                          [&name](const product& p) { return p.getName() == name; });
    
    if (it != products.end()) {
        return std::make_shared<product>(*it);
    }
    return nullptr;
}

bool productController::updateProduct(const product& prod) {
    auto products = getAllProducts();
    
    for (size_t i = 0; i < products.size(); ++i) {
        if (products[i].getId() == prod.getId()) {
            std::vector<std::string> record = {
                std::to_string(prod.getId()),
                prod.getProductID(),
                prod.getName(),
                std::to_string(prod.getPrice()),
                prod.getCategory()
            };
            return csvCtrl->updateRecord(i + 1, record); // +1 for header
        }
    }
    return false;
}

bool productController::deleteProduct(const std::string& productID) {
    auto products = getAllProducts();
    
    for (size_t i = 0; i < products.size(); ++i) {
        if (products[i].getProductID() == productID) {
            return csvCtrl->deleteRecord(i + 1); // +1 for header
        }
    }
    return false;
}

int productController::getNextId() {
    auto products = getAllProducts();
    int maxId = 0;
    
    for (const auto& prod : products) {
        if (prod.getId() > maxId) {
            maxId = prod.getId();
        }
    }
    
    return maxId + 1;
}

bool productController::isProductExists(int id) {
    return getProductById(id) != nullptr;
}

bool productController::isProductNameExists(const std::string& name) {
    return getProductByName(name) != nullptr;
}

std::vector<product> productController::getProductsByCategory(const std::string& category) {
    auto products = getAllProducts();
    std::vector<product> result;
    
    std::copy_if(products.begin(), products.end(), std::back_inserter(result),
                [&category](const product& p) { return p.getCategory() == category; });
    
    return result;
}

void productController::displayAllProducts() {
    auto products = getAllProducts();
    
    if (products.empty()) {
        std::cout << "등록된 제품이 없습니다.\n";
        return;
    }
    
    std::cout << "\n=== 제품 목록 ===\n";
    for (const auto& prod : products) {
        prod.displayInfo();
    }
}

void productController::displayProduct(const product& prod) {
    prod.displayInfo();
} 