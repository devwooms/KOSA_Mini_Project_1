#include "tobacoo.h"
#include <iostream>

using namespace std;

Tobacco::Tobacco() : Product() {}

Tobacco::Tobacco(int id, string name, int price, string type, string brand)
    : Product(id, name, price, type), brand(brand) {}




string Tobacco::getBrand() const {
    return brand;
}

void Tobacco::setBrand(const string& brand) {
    this->brand = brand;
}



// ------------------------------------------------------------
// 제품 정보 출력
// ------------------------------------------------------------

void Tobacco::info() const {
    Product::info();
    cout << "5. 브랜드: " << brand << endl;
}
string Tobacco::toString() const {
    return Product::toString() + "브랜드: " + brand + "\n";
}

// ------------------------------------------------------------
// CSV 관련 메서드
// ------------------------------------------------------------

string Tobacco::toCSV() const {
    return Product::toCSV() + "," + brand;
}

bool Tobacco::parseFromCSV(const vector<string>& data) {
    if (!Product::parseFromCSV(data)) return false;
    if (data.size() < 5) return false;
    
    brand = data[4];
    return true;
}

string Tobacco::getAdditionalCSV() const {
    return brand;
}

bool Tobacco::parseAdditionalCSV(const vector<string>& data) {
    if (data.size() < 5) return false;
    brand = data[4];
    return true;
} 