#include "Product.h"
#include <iostream>
#include <sstream>

const std::string Product::FILENAME = "products.csv";
const std::string Product::FOLDER_PATH = "model/data";

Product::Product() : id(0), productID(""), name(""), price(0), category(""), description("") {}

Product::Product(int id, const std::string& productID, const std::string& name, int price, const std::string& category, const std::string& description)
    : id(id), productID(productID), name(name), price(price), category(category), description(description) {}

std::string Product::toString() const {
    std::ostringstream oss;
    oss << "ID: " << id << ", 제품ID: " << productID << ", 이름: " << name << ", 가격: " << price 
        << "원, 카테고리: " << category;
    if (!description.empty()) {
        oss << ", 설명: " << description;
    }
    return oss.str();
}

std::string Product::toCSV() const {
    std::ostringstream oss;
    oss << id << "," << productID << "," << name << "," << price << "," << category;
    return oss.str();
}

bool Product::parseFromCSV(const std::vector<std::string>& data) {
    if (data.size() < 5) return false;
    
    try {
        id = std::stoi(data[0]);
        productID = data[1];
        name = data[2];
        price = std::stoi(data[3]);
        category = data[4];
        return true;
    } catch (...) {
        return false;
    }
}

void Product::displayInfo() const {
    std::cout << toString() << std::endl;
} 