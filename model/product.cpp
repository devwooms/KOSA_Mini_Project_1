#include "product.h"
#include <iostream>
#include <sstream>

const std::string product::FILENAME = "products.csv";
const std::string product::FOLDER_PATH = "model/data";

product::product() : id(0), productID(""), name(""), price(0), category(""), description("") {}

product::product(int id, const std::string& productID, const std::string& name, int price, const std::string& category, const std::string& description)
    : id(id), productID(productID), name(name), price(price), category(category), description(description) {}

std::string product::toString() const {
    std::ostringstream oss;
    oss << "ID: " << id << ", 제품ID: " << productID << ", 이름: " << name << ", 가격: " << price 
        << "원, 카테고리: " << category;
    if (!description.empty()) {
        oss << ", 설명: " << description;
    }
    return oss.str();
}

std::string product::toCSV() const {
    std::ostringstream oss;
    oss << id << "," << productID << "," << name << "," << price << "," << category;
    return oss.str();
}

bool product::parseFromCSV(const std::vector<std::string>& data) {
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

void product::displayInfo() const {
    std::cout << toString() << std::endl;
} 