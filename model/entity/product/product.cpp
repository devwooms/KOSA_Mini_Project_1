#include "product.h"
#include <iostream>

using namespace std;

// 정적 변수 초기화
const string Product::FILENAME = "products.csv";
const string Product::FOLDER_PATH = "./data/products";
const string Product::KEYWORD = "products";
const string Product::HEADER = "제품번호,제품명,카테고리,가격";

Product::Product() : pkId(0), name(""), category(""), price(0) {}
Product::Product(int id, string n, string c, int p)
    : pkId(id), name(n), category(c), price(p) {}

// get
int Product::getPkId() const { return pkId; }
string Product::getName() const { return name; }
string Product::getCategory() const { return category; }
int Product::getPrice() const { return price; }

// set
void Product::setPkId(int pkId) { this->pkId = pkId; }
void Product::setName(const string& name) { this->name = name; }
void Product::setCategory(const string& category) { this->category = category; }
void Product::setPrice(int price) { this->price = price; }

// 제품 정보 출력
void Product::info() const {
    cout << "=== 제품 정보 ===" << endl;
    // Primary Key
    cout << "1. 제품 번호: " << pkId << endl;
    cout << "2. 제품명: " << name << endl;
    cout << "3. 카테고리: " << category << endl;
    cout << "4. 가격: " << price << "원" << endl;
}

// 제품 정보 출력 (string)
string Product::toString() const {
    return "제품 번호: " + to_string(pkId) + "\n" +
           "제품명: " + name + "\n" +
           "카테고리: " + category + "\n" +
           "가격: " + to_string(price) + "원\n";
}

// CSV 변환
string Product::toCSV() const {
    return to_string(pkId) + "," + name + "," + category + "," + to_string(price);
}

// CSV 파싱
bool Product::parseFromCSV(const vector<string>& data) {
    if (data.size() < 3) {
        return false;
    }
    // string to int
    pkId = stoi(data[0]);
    name = data[1];
    category = data[2];
    price = stoi(data[3]);
    return true;
}