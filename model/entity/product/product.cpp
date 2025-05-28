#include "product.h"
#include <iostream>

using namespace std;

// 정적 변수 초기화
const string Product::FILENAME = "products.csv";
const string Product::FOLDER_PATH = "./data/products";
const string Product::KEYWORD = "products";

string Product::getCSVHeader() {
    return "pkId,name,price";
}

Product::Product() : pkId(0), name(""), price(0) {}
Product::Product(int id, string n, int p)
    : pkId(id), name(n), price(p) {}

// get
int Product::getPkId() const { return pkId; }
string Product::getName() const { return name; }
int Product::getPrice() const { return price; }

// set
void Product::setPkId(int id) { pkId = id; }
void Product::setName(const string& n) { name = n; }
void Product::setPrice(int p) { price = p; }

// 제품 정보 출력
void Product::info() const {
    cout << "=== 제품 정보 ===" << endl;
    // Primary Key
    cout << "1. 제품 번호: " << pkId << endl;
    cout << "2. 이름: " << name << endl;
    cout << "3. 가격: " << price << "원" << endl;
}

// 제품 정보 출력 (string)
string Product::toString() const {
    return "제품 번호: " + to_string(pkId) + "\n" +
           "이름: " + name + "\n" +
           "가격: " + to_string(price) + "원\n";
}

// CSV 변환
string Product::toCSV() const {
    return to_string(pkId) + "," + name + "," + to_string(price);
}

// CSV 파싱
bool Product::parseFromCSV(const vector<string>& data) {
    if (data.size() < 3) {
        return false;
    }
    // string to int
    pkId = stoi(data[0]);
    name = data[1];
    price = stoi(data[2]);
    return true;
}