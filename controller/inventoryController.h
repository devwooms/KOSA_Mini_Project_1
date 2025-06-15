#ifndef INVENTORY_CONTROLLER_H
#define INVENTORY_CONTROLLER_H

#include <memory>
#include <vector>

#include "BaseController.h"
#include "../model/Inventory.h"

class InventoryController : public BaseController
{
   private:
    static const std::string CSV_PATH;
    std::vector<Inventory> inventories;

    // 인벤토리 목록 로드 (BaseController의 순수 가상 함수 구현)
    void loadData() override;

protected:
    // BaseController의 순수 가상 함수들 구현
    std::string getFilePath() const override;
    std::vector<std::string> getHeaders() const override;

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