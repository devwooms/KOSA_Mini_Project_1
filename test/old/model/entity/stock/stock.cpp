#include "stock.h"
#include <iostream>

using namespace std;

// 정적 멤버 변수 초기화
const string Stock::FILENAME = "stocks.csv";
const string Stock::FOLDER_PATH = "./data/stocks";
const string Stock::KEYWORD = "stocks";

Stock::Stock() : pkId(0), name(""), price(0), quantity(0), expirationDate("") {}
Stock::Stock(int pkId, string name, int price, int quantity, string expirationDate) 
    : pkId(pkId), name(name), price(price), quantity(quantity), expirationDate(expirationDate) {}

int Stock::getPkId() const { return pkId; }
string Stock::getName() const { return name; }
int Stock::getPrice() const { return price; }
int Stock::getQuantity() const { return quantity; }
string Stock::getExpirationDate() const { return expirationDate; }

void Stock::setPkId(int pkId) { this->pkId = pkId; }
void Stock::setName(const string& name) { this->name = name; }
void Stock::setPrice(int price) { this->price = price; }
void Stock::setQuantity(int quantity) { this->quantity = quantity; }
void Stock::setExpirationDate(const string& expirationDate) { this->expirationDate = expirationDate; }


void Stock::info() const {
    cout << "1. 상품 번호: " << pkId << endl;
    cout << "2. 상품 이름: " << name << endl;
    cout << "3. 상품 가격: " << price << "원" << endl;
    cout << "4. 재고 수량: " << quantity << "개" << endl;
    cout << "5. 유통기한: " << expirationDate << endl;
}

string Stock::toString() const {
    return "상품 번호: " + to_string(pkId) + "\n" +
           "상품 이름: " + name + "\n" +
           "상품 가격: " + to_string(price) + "원\n" +
           "재고 수량: " + to_string(quantity) + "개\n" +
           "유통기한: " + expirationDate + "\n";
}

string Stock::toCSV() const {
    return to_string(pkId) + "," + name + "," + to_string(price) + "," + to_string(quantity) + "," + expirationDate;
}

bool Stock::parseFromCSV(const vector<string>& data) {
    // pkId,name,price,quantity,expirationDate
    if (data.size() < 5) return false; 
    
    // Stock 정보 설정
    this->pkId = stoi(data[0]);  // Stock의 pkId도 동일하게 설정
    this->name = data[1];
    this->price = stoi(data[2]);
    this->quantity = stoi(data[3]);
    this->expirationDate = data[4];
    
    return true;
}

