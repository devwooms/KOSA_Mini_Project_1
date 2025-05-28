#include "stock.h"
#include <iostream>

using namespace std;

// 정적 멤버 변수 초기화
const string Stock::FILENAME = "stocks.csv";
const string Stock::FOLDER_PATH = "./data/stocks";
const string Stock::KEYWORD = "stocks";

Stock::Stock() : product(), quantity(0), expirationDate("") {}
Stock::Stock(Product product, int qty, string expDate) 
    : product(product), quantity(qty), expirationDate(expDate) {}

int Stock::getQuantity() const { return quantity; }
string Stock::getExpirationDate() const { return expirationDate; }
const Product& Stock::getProduct() const { return product; }

void Stock::setQuantity(int qty) { quantity = qty; }
void Stock::setExpirationDate(const string& ed) { expirationDate = ed; }

void Stock::info() const {
    product.info();
    cout << "4. 재고 수량: " << quantity << "개" << endl;
    cout << "5. 유통기한: " << expirationDate << endl;
}

string Stock::toString() const {
    return product.toString() + 
           "재고 수량: " + to_string(quantity) + "개\n" +
           "유통기한: " + expirationDate + "\n";
}

string Stock::toCSV() const {
    return product.toCSV() + "," + to_string(quantity) + "," + expirationDate;
}

bool Stock::parseFromCSV(const vector<string>& data) {
    // pkId,name,price,quantity,expirationDate
    if (data.size() < 5) return false; 
    
    if (!product.parseFromCSV(data)) return false;
    
    quantity = stoi(data[3]);
    expirationDate = data[4];
    return true;
}

