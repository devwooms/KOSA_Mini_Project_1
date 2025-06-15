#include "Inventory.h"
#include <iostream>
#include <sstream>

const std::string Inventory::FILENAME = "inventory.csv";
const std::string Inventory::FOLDER_PATH = "data";

Inventory::Inventory() : productID(""), stock(0) {}

Inventory::Inventory(const std::string& productID, int stock)
    : productID(productID), stock(stock) {}

std::string Inventory::toString() const {
    std::ostringstream oss;
    oss << "제품ID: " << productID << ", 재고: " << stock;
    return oss.str();
}

std::string Inventory::toCSV() const {
    std::ostringstream oss;
    oss << productID << "," << stock;
    return oss.str();
}

bool Inventory::parseFromCSV(const std::vector<std::string>& data) {
    if (data.size() < 2) return false;
    
    try {
        productID = data[0];
        stock = std::stoi(data[1]);
        return true;
    } catch (...) {
        return false;
    }
}

void Inventory::displayInfo() const {
    std::cout << toString() << std::endl;
}

bool Inventory::addStock(int amount) {
    if (amount < 0) return false;
    stock += amount;
    return true;
}

bool Inventory::reduceStock(int amount) {
    if (amount < 0 || amount > stock) return false;
    stock -= amount;
    return true;
} 