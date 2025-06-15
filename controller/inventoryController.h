#ifndef INVENTORY_CONTROLLER_H
#define INVENTORY_CONTROLLER_H

#include "../model/Inventory.h"
#include "CsvController.h"
#include <vector>
#include <memory>

class InventoryController {
private:
    std::shared_ptr<CsvController> csvCtrl;
    
public:
    InventoryController();
    
    // CRUD operations
    bool addInventory(const Inventory& inv);
    std::vector<Inventory> getAllInventories();
    std::shared_ptr<Inventory> getInventoryById(int id);
    std::vector<Inventory> getInventoryByProductID(const std::string& productID);
    bool updateInventory(const Inventory& inv);
    bool deleteInventory(const std::string& productID);
    
    // Inventory management
    bool addStock(const std::string& productID, int quantity);
    bool reduceStock(const std::string& productID, int quantity);
    int getTotalQuantityByProductID(const std::string& productID);
    
    // Utility methods
    int getNextId();
    bool isInventoryExists(int id);
    std::vector<Inventory> getLowStockItems(int threshold = 10);
    
    // Display methods
    void displayAllInventory();
    void displayInventory(const Inventory& inv);
    void displayLowStockAlert(int threshold = 10);
};

#endif // INVENTORY_CONTROLLER_H 