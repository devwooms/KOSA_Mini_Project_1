#include "InventoryController.h"
#include <iostream>
#include <algorithm>
#include <numeric>

InventoryController::InventoryController() {
    Inventory tempInventory;
    std::string filepath = tempInventory.getFolderPath() + "/" + tempInventory.getFilename();
    csvCtrl = std::make_shared<CsvController>(filepath);
    
    // 헤더가 없으면 초기화
    if (csvCtrl->getRecordCount() == 0) {
        csvCtrl->initializeWithHeaders({"ID", "ProductID", "Quantity", "MinStock", "MaxStock"});
    }
}

bool InventoryController::addInventory(const Inventory& inv) {
    std::vector<std::string> record = {
        std::to_string(getNextId()),
        inv.getProductID(),
        std::to_string(inv.getQuantity()),
        std::to_string(inv.getMinStock()),
        std::to_string(inv.getMaxStock())
    };
    
    return csvCtrl->addRecord(record);
}

std::vector<Inventory> InventoryController::getAllInventories() {
    std::vector<Inventory> inventories;
    auto records = csvCtrl->readAllRecords();
    
    // 첫 번째 행이 헤더인 경우 건너뛰기
    for (size_t i = 1; i < records.size(); ++i) {
        Inventory inv;
        if (inv.parseFromCSV(records[i])) {
            inventories.push_back(inv);
        }
    }
    
    return inventories;
}

std::shared_ptr<Inventory> InventoryController::getInventoryById(int id) {
    auto inventories = getAllInventories();
    auto it = std::find_if(inventories.begin(), inventories.end(),
                          [id](const Inventory& inv) { return inv.getId() == id; });
    
    if (it != inventories.end()) {
        return std::make_shared<Inventory>(*it);
    }
    return nullptr;
}

std::vector<Inventory> InventoryController::getInventoryByProductID(const std::string& productID) {
    auto inventories = getAllInventories();
    std::vector<Inventory> result;
    
    std::copy_if(inventories.begin(), inventories.end(), std::back_inserter(result),
                [&productID](const Inventory& inv) { return inv.getProductID() == productID; });
    
    return result;
}

bool InventoryController::updateInventory(const Inventory& inv) {
    auto inventories = getAllInventories();
    
    for (size_t i = 0; i < inventories.size(); ++i) {
        if (inventories[i].getId() == inv.getId()) {
            std::vector<std::string> record = {
                std::to_string(inv.getId()),
                inv.getProductID(),
                std::to_string(inv.getQuantity()),
                std::to_string(inv.getMinStock()),
                std::to_string(inv.getMaxStock())
            };
            return csvCtrl->updateRecord(i + 1, record); // +1 for header
        }
    }
    return false;
}

bool InventoryController::deleteInventory(const std::string& productID) {
    auto inventories = getAllInventories();
    
    for (size_t i = 0; i < inventories.size(); ++i) {
        if (inventories[i].getProductID() == productID) {
            return csvCtrl->deleteRecord(i + 1); // +1 for header
        }
    }
    return false;
}

bool InventoryController::addStock(const std::string& productID, int quantity) {
    auto inventories = getInventoryByProductID(productID);
    
    if (inventories.empty()) {
        return false; // 해당 제품의 재고가 없음
    }
    
    // 첫 번째 재고 항목에 수량 추가
    auto& firstInventory = inventories[0];
    firstInventory.addQuantity(quantity);
    return updateInventory(firstInventory);
}

bool InventoryController::reduceStock(const std::string& productID, int quantity) {
    auto inventories = getInventoryByProductID(productID);
    
    if (inventories.empty()) {
        return false;
    }
    
    int totalQuantity = getTotalQuantityByProductID(productID);
    if (totalQuantity < quantity) {
        return false; // 재고 부족
    }
    
    // 재고에서 차감
    for (auto& inv : inventories) {
        if (quantity <= 0) break;
        
        int currentQuantity = inv.getQuantity();
        if (currentQuantity >= quantity) {
            inv.reduceQuantity(quantity);
            updateInventory(inv);
            quantity = 0;
        } else {
            inv.reduceQuantity(currentQuantity);
            updateInventory(inv);
            quantity -= currentQuantity;
        }
    }
    
    return quantity == 0;
}

int InventoryController::getTotalQuantityByProductID(const std::string& productID) {
    auto inventories = getInventoryByProductID(productID);
    return std::accumulate(inventories.begin(), inventories.end(), 0,
                            [](int sum, const Inventory& inv) { return sum + inv.getQuantity(); });
}

int InventoryController::getNextId() {
    auto inventories = getAllInventories();
    int maxId = 0;
    
    for (const auto& inv : inventories) {
        if (inv.getId() > maxId) {
            maxId = inv.getId();
        }
    }
    
    return maxId + 1;
}

bool InventoryController::isInventoryExists(int id) {
    return getInventoryById(id) != nullptr;
}

std::vector<Inventory> InventoryController::getLowStockItems(int threshold) {
    auto inventories = getAllInventories();
    std::vector<Inventory> lowStockItems;
    
    std::copy_if(inventories.begin(), inventories.end(), std::back_inserter(lowStockItems),
                [threshold](const Inventory& inv) { return inv.getQuantity() <= threshold; });
    
    return lowStockItems;
}

void InventoryController::displayAllInventory() {
    auto inventories = getAllInventories();
    
    if (inventories.empty()) {
        std::cout << "등록된 재고가 없습니다.\n";
        return;
    }
    
    std::cout << "\n=== 재고 목록 ===\n";
    for (const auto& inv : inventories) {
        inv.displayInfo();
    }
}

void InventoryController::displayInventory(const Inventory& inv) {
    inv.displayInfo();
}

void InventoryController::displayLowStockAlert(int threshold) {
    auto lowStockItems = getLowStockItems(threshold);
    
    if (lowStockItems.empty()) {
        std::cout << "재고 부족 항목이 없습니다.\n";
        return;
    }
    
    std::cout << "\n⚠️  재고 부족 경고 ⚠️\n";
    for (const auto& inv : lowStockItems) {
        std::cout << "- " << inv.getProductID() << ": " << inv.getQuantity() << "개 (최소: " << inv.getMinStock() << "개)\n";
    }
} 