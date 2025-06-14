#include "drink.h"
#include <iostream>

using namespace std;

Drink::Drink() : Product(), isCarbonated(0) {}

Drink::Drink(int id, string name, int price, string type, int isCarbonated)
    : Product(id, name, price, type), isCarbonated(isCarbonated) {}

int Drink::getIsCarbonated() const {
    return isCarbonated;
}

void Drink::setIsCarbonated(int isCarbonated) {
    this->isCarbonated = isCarbonated;
}

// ------------------------------------------------------------
// 제품 정보 출력
// ------------------------------------------------------------

void Drink::info() const {
    Product::info();
    cout << "5. 탄산여부: " << (isCarbonated == 1 ? "있음" : "없음") << endl;
}

string Drink::toString() const {
    return Product::toString() + "탄산여부: " + (isCarbonated == 1 ? "있음" : "없음") + "\n";
}

// ------------------------------------------------------------
// CSV 관련 메서드
// ------------------------------------------------------------

string Drink::toCSV() const {
    return Product::toCSV() + "," + to_string(isCarbonated);
}

bool Drink::parseFromCSV(const vector<string>& data) {
    if (!Product::parseFromCSV(data)) return false;
    if (data.size() < 5) return false;
    
    isCarbonated = stoi(data[4]);
    return true;
}

string Drink::getAdditionalCSV() const {
    return to_string(isCarbonated);
}

bool Drink::parseAdditionalCSV(const vector<string>& data) {
    if (data.size() < 5) return false;
    isCarbonated = stoi(data[4]);
    return true;
} 