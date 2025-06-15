#ifndef INVENTORY_CONTROLLER_H
#define INVENTORY_CONTROLLER_H

#include <memory>
#include <vector>

#include "../data/CsvRepository.h"
#include "../model/Inventory.h"

class InventoryController
{
   private:
    static const std::string CSV_PATH;
    std::shared_ptr<CsvRepository> csvRepo;
    std::vector<Inventory> inventories;

    // 인벤토리 목록 로드
    void loadInventories();

   public:
    InventoryController();

    // 모든 인벤토리 조회
    std::vector<Inventory> getAllInventories();

    // 특정 제품 ID로 인벤토리 조회
    Inventory* findInventoryByProductID(const std::string& productID);

    // 인벤토리 추가
    bool addInventory(const std::string& productID, int stock);

    // 인벤토리 업데이트
    bool updateInventory(const std::string& productID, int stock);

    // 재고 수량 조회
    int getStock(const std::string& productID);
};

#endif  // INVENTORY_CONTROLLER_H