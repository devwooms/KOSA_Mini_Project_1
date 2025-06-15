#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>

class Inventory {
private:
    static const std::string FILENAME;
    static const std::string FOLDER_PATH;
    
    int id;
    std::string productID;
    int quantity;
    int minStock;
    int maxStock;

public:
    Inventory();
    Inventory(int id, const std::string& productID, int quantity, int minStock, int maxStock);
    
    // Getters
    int getId() const { return id; }
    std::string getProductID() const { return productID; }
    int getQuantity() const { return quantity; }
    int getMinStock() const { return minStock; }
    int getMaxStock() const { return maxStock; }
    
    // Setters
    void setId(int id) { this->id = id; }
    void setProductID(const std::string& productID) { this->productID = productID; }
    void setQuantity(int quantity) { this->quantity = quantity; }
    void setMinStock(int minStock) { this->minStock = minStock; }
    void setMaxStock(int maxStock) { this->maxStock = maxStock; }
    
    // CSV 관련
    std::string getFilename() const { return FILENAME; }
    std::string getFolderPath() const { return FOLDER_PATH; }
    
    // 유틸리티
    std::string toString() const;
    std::string toCSV() const;
    bool parseFromCSV(const std::vector<std::string>& data);
    void displayInfo() const;
    
    // 재고 관리
    bool addQuantity(int amount);
    bool reduceQuantity(int amount);
};

#endif // INVENTORY_H 