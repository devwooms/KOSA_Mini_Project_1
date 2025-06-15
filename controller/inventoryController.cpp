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
        csvCtrl->initializeWithHeaders({"ProductID", "Stock"});
    }
}

bool InventoryController::addInventory(const Inventory& inv) {
    std::vector<std::string> record = {
        inv.getProductID(),
        std::to_string(inv.getStock())
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

std::shared_ptr<Inventory> InventoryController::getInventoryByProductID(const std::string& productID) {
    auto inventories = getAllInventories();
    auto it = std::find_if(inventories.begin(), inventories.end(),
                          [&productID](const Inventory& inv) { return inv.getProductID() == productID; });
    
    if (it != inventories.end()) {
        return std::make_shared<Inventory>(*it);
    }
    return nullptr;
}

bool InventoryController::updateInventory(const Inventory& inv) {
    auto inventories = getAllInventories();
    
    for (size_t i = 0; i < inventories.size(); ++i) {
        if (inventories[i].getProductID() == inv.getProductID()) {
            std::vector<std::string> record = {
                inv.getProductID(),
                std::to_string(inv.getStock())
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
    auto inventory = getInventoryByProductID(productID);
    
    if (!inventory) {
        return false; // 해당 제품의 재고가 없음
    }
    
    // 재고 수량 추가
    inventory->addStock(quantity);
    return updateInventory(*inventory);
}

bool InventoryController::reduceStock(const std::string& productID, int quantity) {
    auto inventory = getInventoryByProductID(productID);
    
    if (!inventory) {
        return false;
    }
    
    int currentStock = inventory->getStock();
    if (currentStock < quantity) {
        return false; // 재고 부족
    }
    
    // 재고에서 차감
    inventory->reduceStock(quantity);
    return updateInventory(*inventory);
}

int InventoryController::getStockByProductID(const std::string& productID) {
    auto inventory = getInventoryByProductID(productID);
    return inventory ? inventory->getStock() : 0;
}

bool InventoryController::isInventoryExists(const std::string& productID) {
    return getInventoryByProductID(productID) != nullptr;
}

std::vector<Inventory> InventoryController::getLowStockItems(int threshold) {
    auto inventories = getAllInventories();
    std::vector<Inventory> lowStockItems;
    
    std::copy_if(inventories.begin(), inventories.end(), std::back_inserter(lowStockItems),
                [threshold](const Inventory& inv) { return inv.getStock() <= threshold; });
    
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
        std::cout << "- " << inv.getProductID() << ": " << inv.getStock() << "개 (기준: " << threshold << "개 이하)\n";
    }
} 