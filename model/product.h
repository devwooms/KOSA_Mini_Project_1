#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>

class Product {
private:
    static const std::string FILENAME;
    static const std::string FOLDER_PATH;
    
    int id;
    std::string productID;
    std::string name;
    int price;
    std::string category;
    std::string description;

public:
    Product();
    Product(int id, const std::string& productID, const std::string& name, int price, const std::string& category, const std::string& description = "");
    
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
    
    // CSV 관련
    std::string getFilename() const { return FILENAME; }
    std::string getFolderPath() const { return FOLDER_PATH; }
    
    // 유틸리티
    std::string toString() const;
    std::string toCSV() const;
    bool parseFromCSV(const std::vector<std::string>& data);
    void displayInfo() const;
};

#endif // PRODUCT_H 