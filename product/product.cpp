#include "product.h"
#include <iostream>

using namespace std;

Product::Product() : productId(0), name(""), category(""), price(0), brand(""), rewardpoints(0), expirationDate(0), wholesalePrice(0) {}
Product::Product(int id, string n, string c, int p, string b, float r, float e, int w)
    : productId(id), name(n), category(c), price(p), brand(b), rewardpoints(r), expirationDate(e), wholesalePrice(w) {}

// get
int Product::getProductId() const { return productId; }
string Product::getName() const { return name; }
string Product::getCategory() const { return category; }
int Product::getPrice() const { return price; }
string Product::getBrand() const { return brand; }
float Product::getrewardpoints() const { return rewardpoints; }
float Product::getExpirationDate() const { return expirationDate; }
int Product::getWholesalePrice() const { return wholesalePrice; }

// set
void Product::setProductId(int id) { productId = id; }
void Product::setName(const string& n) { name = n; }
void Product::setCategory(const string& c) { category = c; }
void Product::setPrice(int p) { price = p; }
void Product::setBrand(const string& b) { brand = b; }
void Product::setrewardpoints(float s) { rewardpoints = s; }
void Product::setExpirationDate(float e) { expirationDate = e; }
void Product::setWholesalePrice(int w) { wholesalePrice = w; }

// 제품 정보 출력
void Product::info() const {
    cout << "\\n=== 제품 정보 ===" << endl;
    cout << "제품 번호: " << productId << endl;
    cout << "이름: " << name << endl;
    cout << "카테고리: " << category << endl;
    cout << "가격: " << price << "원" << endl;
    cout << "브랜드: " << brand << endl;
    cout << "적립 포인트: " << price * rewardpoints << endl;
    cout << "이벤트 할인: " << price * expirationDate << endl;
    cout << "업체가격: " << wholesalePrice << "원" << endl;
}
