#include "instantMeal.h"
#include <iostream>

using namespace std;

InstantMeal::InstantMeal() : Product(), isFrozen(0) {}

InstantMeal::InstantMeal(int id, string name, int price, string type, int isFrozen)
    : Product(id, name, price, type), isFrozen(isFrozen) {}

int InstantMeal::getIsFrozen() const {
    return isFrozen;
}

void InstantMeal::setIsFrozen(int isFrozen) {
    this->isFrozen = isFrozen;
}







string InstantMeal::getAdditionalCSV() const {return to_string(isFrozen);}
bool InstantMeal::parseAdditionalCSV(const vector<string>& data) {
isFrozen = stoi(data[4]);
    return true;
}


// ------------------------------------------------------------
// 제품 정보 출력
// ------------------------------------------------------------

void InstantMeal::info() const {
    Product::info();
    cout << "5. 보관 방법: " << (isFrozen == 1 ? "냉동" : "냉장") << endl;
}

string InstantMeal::toString() const {
    return Product::toString() + 
        "보관 방법: " + (isFrozen == 1 ? "냉동" : "냉장") + "\n";
}

// ------------------------------------------------------------
// CSV 관련 메서드
// ------------------------------------------------------------

string InstantMeal::toCSV() const {
    return Product::toCSV() + "," + to_string(isFrozen);
}

bool InstantMeal::parseFromCSV(const vector<string>& data) {
    if (!Product::parseFromCSV(data)) return false;
    if (data.size() < 5) return false;
    
    isFrozen = stoi(data[4]);
    return true;
} 