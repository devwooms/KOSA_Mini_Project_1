#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>

class Inventory {
private:
    static const std::string FILENAME;
    static const std::string FOLDER_PATH;
    
    std::string productID;
    int stock;

public:
    Inventory();
    Inventory(const std::string& productID, int stock);
    
    // Getters
    std::string getProductID() const { return productID; }
    int getStock() const { return stock; }
    
    // Setters
    void setProductID(const std::string& productID) { this->productID = productID; }
    void setStock(int stock) { this->stock = stock; }
    
    // CSV 관련
    std::string getFilename() const { return FILENAME; }
    std::string getFolderPath() const { return FOLDER_PATH; }
    
    // 유틸리티
    std::string toString() const;
    std::string toCSV() const;
    bool parseFromCSV(const std::vector<std::string>& data);
    void displayInfo() const;
    
    // 재고 관리
    bool addStock(int amount);
    bool reduceStock(int amount);
};

#endif // INVENTORY_H 