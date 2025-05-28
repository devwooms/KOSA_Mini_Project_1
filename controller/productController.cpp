#include "productController.h"

ProductController::ProductController() {
    // 생성자 구현
}

ProductController::~ProductController() {
    // 소멸자 구현
}

vector<Product> ProductController::getAll() {
    Product product;
    return productCsvController.loadCSV(product);
}

bool ProductController::add(const Product& product) {
    productCsvController.saveCSV(product);
    return true;
}

bool ProductController::update(const Product& product) {
    // 1. 모든 제품을 로드
    Product temp;
    vector<Product> products = productCsvController.loadCSV(temp);
    
    // 2. 해당 제품을 찾아서 업데이트
    auto it = find_if(products.begin(), products.end(),
        [&product](const Product& p) { return p.getPkId() == product.getPkId(); });
    
    if (it == products.end()) {
        cout << "업데이트할 제품을 찾지 못했습니다." << endl;
        return false;
    }
    
    // 제품 정보 업데이트
    *it = product;
    
    // 3. 전체 목록을 다시 저장
    string fullPath = temp.getFolderPath() + "/" + temp.getFilename();
    ofstream file(fullPath, ios::trunc);  // 파일을 새로 생성
    if (!file.is_open()) {
        cout << "파일을 열 수 없습니다." << endl;
        return false;
    }
    
    // 모든 제품을 다시 저장
    for (size_t i = 0; i < products.size(); ++i) {
        file << products[i].toCSV();
        if (i < products.size() - 1) {
            file << "\n";
        }
    }
    
    file.close();
    cout << "제품 정보가 업데이트되었습니다." << endl;
    return true;
}

bool ProductController::remove(int pkId) {
    // 1. 모든 제품을 로드
    Product product;
    vector<Product> products = productCsvController.loadCSV(product);
    
    // 2. 해당 제품을 찾아서 제거
    // find_if 조건에 맞는 첫 번째 요소를 찾아주는 함수
    auto it = find_if(products.begin(), products.end(),
        [pkId](const Product& p) { return p.getPkId() == pkId; });
    
    if (it == products.end()) {
        cout << "제품을 찾지 못했습니다." << endl;
        return false;  // 제품을 찾지 못함
    }
    
    products.erase(it);
    
    // 3. 전체 목록을 다시 저장
    string fullPath = product.getFolderPath() + "/" + product.getFilename();
    ofstream file(fullPath, ios::trunc);  // 파일을 새로 생성
    if (!file.is_open()) {
        return false;
    }
    
    // 모든 제품을 다시 저장
    for (size_t i = 0; i < products.size(); ++i) {
        file << products[i].toCSV();
        if (i < products.size() - 1) {
            file << "\n";
        }
    }
    
    file.close();
    return true;
}