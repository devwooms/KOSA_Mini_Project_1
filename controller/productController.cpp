#include "ProductController.h"
#include <iostream>
#include <algorithm>

ProductController::ProductController() {
    Product tempProduct;
    std::string filepath = tempProduct.getFolderPath() + "/" + tempProduct.getFilename();
    csvCtrl = std::make_shared<CsvController>(filepath);
    
    // 헤더가 없으면 초기화
    if (csvCtrl->getRecordCount() == 0) {
        csvCtrl->initializeWithHeaders({"ID", "ProductID", "Name", "Price", "Category"});
    }
}

bool ProductController::addProduct(const Product& prod) {
    std::vector<std::string> record = {
        std::to_string(getNextId()),
        prod.getProductID(),
        prod.getName(),
        std::to_string(prod.getPrice()),
        prod.getCategory()
    };
    
    return csvCtrl->addRecord(record);
}

std::vector<Product> ProductController::getAllProducts() {
    std::vector<Product> products;
    auto records = csvCtrl->readAllRecords();
    
    // 첫 번째 행이 헤더인 경우 건너뛰기
    for (size_t i = 1; i < records.size(); ++i) {
        Product prod;
        if (prod.parseFromCSV(records[i])) {
            products.push_back(prod);
        }
    }
    
    return products;
}

std::shared_ptr<Product> ProductController::getProductById(int id) {
    auto products = getAllProducts();
    auto it = std::find_if(products.begin(), products.end(),
                          [id](const Product& p) { return p.getId() == id; });
    
    if (it != products.end()) {
        return std::make_shared<Product>(*it);
    }
    return nullptr;
}

std::shared_ptr<Product> ProductController::getProductByName(const std::string& name) {
    auto products = getAllProducts();
    auto it = std::find_if(products.begin(), products.end(),
                          [&name](const Product& p) { return p.getName() == name; });
    
    if (it != products.end()) {
        return std::make_shared<Product>(*it);
    }
    return nullptr;
}

bool ProductController::updateProduct(const Product& prod) {
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

bool ProductController::deleteProduct(const std::string& productID) {
    auto products = getAllProducts();
    
    for (size_t i = 0; i < products.size(); ++i) {
        if (products[i].getProductID() == productID) {
            return csvCtrl->deleteRecord(i + 1); // +1 for header
        }
    }
    return false;
}

int ProductController::getNextId() {
    auto products = getAllProducts();
    int maxId = 0;
    
    for (const auto& prod : products) {
        if (prod.getId() > maxId) {
            maxId = prod.getId();
        }
    }
    
    return maxId + 1;
}

bool ProductController::isProductExists(int id) {
    return getProductById(id) != nullptr;
}

bool ProductController::isProductNameExists(const std::string& name) {
    return getProductByName(name) != nullptr;
}

std::vector<Product> ProductController::getProductsByCategory(const std::string& category) {
    auto products = getAllProducts();
    std::vector<Product> result;
    
    std::copy_if(products.begin(), products.end(), std::back_inserter(result),
                [&category](const Product& p) { return p.getCategory() == category; });
    
    return result;
}

void ProductController::displayAllProducts() {
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

void ProductController::displayProduct(const Product& prod) {
    prod.displayInfo();
} 