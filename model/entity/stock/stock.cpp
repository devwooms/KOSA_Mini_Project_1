#include "stock.h"
#include <iostream>

using namespace std;

// 정적 멤버 변수 초기화
const string Stock::FILENAME = "stocks.csv";
const string Stock::FOLDER_PATH = "./data/stocks";
const string Stock::KEYWORD = "stocks";

Stock::Stock() : product(), quantity(0), expirationDate(""), pkId(0) {}
Stock::Stock(int pkId, Product product, int quantity, string expirationDate) 
    : product(product), quantity(quantity), expirationDate(expirationDate), pkId(pkId) {}

int Stock::getPkId() const { return pkId; }
int Stock::getQuantity() const { return quantity; }
string Stock::getExpirationDate() const { return expirationDate; }
const Product& Stock::getProduct() const { return product; }

void Stock::setPkId(int pkId) { this->pkId = pkId; }
void Stock::setQuantity(int quantity) { this->quantity = quantity; }
void Stock::setExpirationDate(const string& expirationDate) { this->expirationDate = expirationDate; }

void Stock::setProduct(Product product) { this->product = product; }


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
    
    // Product 정보 설정
    Product tempProduct;
    tempProduct.setPkId(stoi(data[0]));
    tempProduct.setName(data[1]);
    tempProduct.setPrice(stoi(data[2]));
    
    // Stock 정보 설정
    this->pkId = stoi(data[0]);  // Stock의 pkId도 동일하게 설정
    this->product = tempProduct;
    this->quantity = stoi(data[3]);
    this->expirationDate = data[4];
    
    return true;
}

