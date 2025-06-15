#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product
{
   private:
    int id;
    std::string productID;
    std::string name;
    int price;
    std::string category;
    std::string description;

   public:
    // 생성자
    Product();
    Product(int id, const std::string& productID, const std::string& name, int price,
            const std::string& category, const std::string& description = "");

    // Getters
    int getId() const { return id; }
    std::string getProductID() const { return productID; }
    std::string getName() const { return name; }
    int getPrice() const { return price; }
    std::string getCategory() const { return category; }
    std::string getDescription() const { return description; }

    // Setters
    void setId(int id) { this->id = id; }
    void setProductID(const std::string& productID) { this->productID = productID; }
    void setName(const std::string& name) { this->name = name; }
    void setPrice(int price) { this->price = price; }
    void setCategory(const std::string& category) { this->category = category; }
    void setDescription(const std::string& description) { this->description = description; }
};

#endif  // PRODUCT_H