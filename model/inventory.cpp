#include "inventory.h"
#include <iostream>
#include <sstream>

const std::string inventory::FILENAME = "inventory.csv";
const std::string inventory::FOLDER_PATH = "model/data";

inventory::inventory() : id(0), productID(""), quantity(0), minStock(0), maxStock(0) {}

inventory::inventory(int id, const std::string& productID, int quantity, int minStock, int maxStock)
    : id(id), productID(productID), quantity(quantity), minStock(minStock), maxStock(maxStock) {}

std::string inventory::toString() const {
    std::ostringstream oss;
    oss << "ID: " << id << ", 제품ID: " << productID << ", 수량: " << quantity 
        << ", 최소재고: " << minStock << ", 최대재고: " << maxStock;
    return oss.str();
}

std::string inventory::toCSV() const {
    std::ostringstream oss;
    oss << id << "," << productID << "," << quantity << "," << minStock << "," << maxStock;
    return oss.str();
}

bool inventory::parseFromCSV(const std::vector<std::string>& data) {
    if (data.size() < 5) return false;
    
    try {
        id = std::stoi(data[0]);
        productID = data[1];
        quantity = std::stoi(data[2]);
        minStock = std::stoi(data[3]);
        maxStock = std::stoi(data[4]);
        return true;
    } catch (...) {
        return false;
    }
}

void inventory::displayInfo() const {
    std::cout << toString() << std::endl;
}

bool inventory::addQuantity(int amount) {
    if (amount < 0) return false;
    quantity += amount;
    return true;
}

bool inventory::reduceQuantity(int amount) {
    if (amount < 0 || amount > quantity) return false;
    quantity -= amount;
    return true;
} 