#include "product.h"
#include <iostream>

using namespace std;

// 정적 변수 초기화
const string Product::FILENAME = "products.csv";
const string Product::FOLDER_PATH = "./data/products";
const string Product::KEYWORD = "products";

Product::Product() : pkId(0), name(""), price(0), productType("") {}

Product::Product(int id, string name, int price, string productType)
    : pkId(id), name(name), price(price), productType(productType) {}

// get
int Product::getPkId() const { return pkId; }
string Product::getName() const { return name; }
int Product::getPrice() const { return price; }
string Product::getProductType() const { return productType; }

// set
void Product::setPkId(int id) { pkId = id; }
void Product::setName(const string& name) { this->name = name; }
void Product::setPrice(int price) { this->price = price; }
void Product::setProductType(const string& productType) { this->productType = productType; }


// ------------------------------------------------------------
// 제품 정보 출력
// ------------------------------------------------------------
void Product::info() const {
    cout << "=== 제품 정보 ===" << endl;
    cout << "1. 제품 번호: " << pkId << endl;
    cout << "2. 제품명: " << name << endl;
    cout << "3. 가격: " << price << "원" << endl;   
    cout << "4. 제품 타입: " << productType << endl;
}

// 제품 정보 출력 (string)
string Product::toString() const {
    return "제품 번호: " + to_string(pkId) + "\n" +
           "제품명: " + name + "\n" +
           "가격: " + to_string(price) + "원\n" +
           "제품 타입: " + productType + "\n";
}

// ------------------------------------------------------------
// CSV 관련 메서드
// ------------------------------------------------------------
// CSV 변환
string Product::toCSV() const {
    string baseInfo = to_string(pkId) + "," + 
                     name + "," + 
                     to_string(price) + "," +
                     productType;
    
    return baseInfo;
}

// CSV 파싱
bool Product::parseFromCSV(const vector<string>& data) {
    if (data.size() < 4) {
        cout << "CSV 데이터 부족: 최소 4개 필요, 현재 " << data.size() << "개" << endl;
        return false;
    }
    
    try {
        pkId = stoi(data[0]);
        name = data[1];
        price = stoi(data[2]);
        productType = data[3];
        
        return true;
    } catch (const exception& e) {
        cout << "CSV 파싱 중 에러 발생: " << e.what() << endl;
        return false;
    }
}