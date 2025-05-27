#include <iostream>
#include <string>


class Product {
private:
    std::string name;
    int price;
    std::string category;
    std::string brand;

public:
    // 생성자
    Product() : name(""), category(""), price(0), brand("") {}
    Product(std::string n, std::string c, int p, std::string b) 
        : name(n), category(c), price(p), brand(b) {}

    // getter 메서드
    std::string getName() const { return name; }
    std::string getCategory() const { return category; }
    int getPrice() const { return price; }
    std::string getBrand() const { return brand; }

    // setter 메서드
    void setName(const std::string& n) { name = n; }
    void setCategory(const std::string& c) { category = c; }
    void setPrice(int p) { price = p; }
    void setBrand(const std::string& b) { brand = b; }

    // 제품 정보 출력
    void displayInfo() const {
        std::cout << "\n=== 제품 정보 ===" << std::endl;
        std::cout << "이름: " << name << std::endl;
        std::cout << "카테고리: " << category << std::endl;
        std::cout << "가격: " << price << "원" << std::endl;
        std::cout << "브랜드: " << brand << std::endl;
    }
};