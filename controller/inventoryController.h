#ifndef INVENTORY_CONTROLLER_H
#define INVENTORY_CONTROLLER_H

#include "../model/inventory.h"
#include "csvController.h"
#include <vector>
#include <memory>

class inventoryController {
private:
    std::shared_ptr<csvController> csvCtrl;
    
public:
    inventoryController();
    
    // CRUD operations
    bool addInventory(const inventory& inv);
    std::vector<inventory> getAllInventories();
    std::shared_ptr<inventory> getInventoryById(int id);
    std::vector<inventory> getInventoryByProductID(const std::string& productID);
    bool updateInventory(const inventory& inv);
    bool deleteInventory(const std::string& productID);
    
    // Inventory management
    bool addStock(const std::string& productID, int quantity);
    bool reduceStock(const std::string& productID, int quantity);
    int getTotalQuantityByProductID(const std::string& productID);
    
    // Utility methods
    int getNextId();
    bool isInventoryExists(int id);
    std::vector<inventory> getLowStockItems(int threshold = 10);
    
    // Display methods
    void displayAllInventory();
    void displayInventory(const inventory& inv);
    void displayLowStockAlert(int threshold = 10);
};

#endif // INVENTORY_CONTROLLER_H 