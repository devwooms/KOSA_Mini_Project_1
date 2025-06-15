#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>

class Inventory
{
   private:
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
};

#endif  // INVENTORY_H