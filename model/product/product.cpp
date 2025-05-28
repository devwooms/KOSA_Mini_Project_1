#include "product.h"
#include <iostream>

using namespace std;

// 정적 변수 초기화
const string Product::FILENAME = "products.csv";
const string Product::FOLDER_PATH = "./data/products";
const string Product::KEYWORD = "products";

Product::Product() : productId(0), name(""), category(""), price(0), brand(""), rewardpoints(0), expirationDate(0), wholesalePrice(0) {}
Product::Product(int id, string n, string c, int p, string b, int r, int e, int w)
    : productId(id), name(n), category(c), price(p), brand(b), rewardpoints(r), expirationDate(e), wholesalePrice(w) {}

// get
int Product::getProductId() const { return productId; }
string Product::getName() const { return name; }
string Product::getCategory() const { return category; }
int Product::getPrice() const { return price; }
string Product::getBrand() const { return brand; }
int Product::getrewardpoints() const { return rewardpoints; }
int Product::getExpirationDate() const { return expirationDate; }
int Product::getWholesalePrice() const { return wholesalePrice; }

// set
void Product::setProductId(int id) { productId = id; }
void Product::setName(const string& n) { name = n; }
void Product::setCategory(const string& c) { category = c; }
void Product::setPrice(int p) { price = p; }
void Product::setBrand(const string& b) { brand = b; }
void Product::setrewardpoints(int s) { rewardpoints = s; }
void Product::setExpirationDate(int e) { expirationDate = e; }
void Product::setWholesalePrice(int w) { wholesalePrice = w; }

// 제품 정보 출력
void Product::info() const {
    cout << "\\n=== 제품 정보 ===" << endl;
    cout << "1. 제품 번호: " << productId << endl;
    cout << "2. 이름: " << name << endl;
    cout << "3. 카테고리: " << category << endl;
    cout << "4. 가격: " << price << "원" << endl;
    cout << "5. 브랜드: " << brand << endl;
    cout << "6. 적립 포인트: " << price * rewardpoints << endl;
    cout << "7. 이벤트 할인: " << price * expirationDate << endl;
    cout << "8. 업체가격: " << wholesalePrice << "원" << endl;
}

string Product::toString() const {
    return "제품 번호: " + to_string(productId) + "\n" +
           "이름: " + name + "\n" +
           "카테고리: " + category + "\n" +
           "가격: " + to_string(price) + "원\n" +
           "브랜드: " + brand + "\n" +
           "적립 포인트: " + to_string(price * rewardpoints) + "\n" +
           "이벤트 할인: " + to_string(price * expirationDate) + "\n" +
           "업체가격: " + to_string(wholesalePrice) + "원\n";
}

string Product::toCSV() const {
    return to_string(productId) + "," 
    + name + "," 
    + category + "," 
    + to_string(price) + "," 
    + brand + "," 
    + to_string(rewardpoints) + "," 
    + to_string(expirationDate) + "," 
    + to_string(wholesalePrice);
}