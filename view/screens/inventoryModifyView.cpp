#include "InventoryModifyView.h"


InventoryModifyView::InventoryModifyView() {
    invCtrl = std::make_shared<InventoryController>();
    prodCtrl = std::make_shared<ProductController>();
    setTitle("재고 증가/차감");
    setMenuItems({
        "뒤로가기"
    });
    setMenuActions({
        [this]() { goBack(); }
    });
}
    
void InventoryModifyView::modifyInventory() {
    std::cout << "\n=== 재고 증가/차감 ===\n";
    
    // 현재 재고 목록 표시
    auto inventories = invCtrl->getAllInventories();
    auto products = prodCtrl->getAllProducts();
    
    if (inventories.empty()) {
        std::cout << "등록된 재고가 없습니다.\n";
        std::cout << "아무 키나 눌러주세요...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    
    std::cout << "\n현재 재고 현황:\n";
    for (const auto& inv : inventories) {
        auto productIt = std::find_if(products.begin(), products.end(),
            [&inv](const Product& p) { return p.getProductID() == inv.getProductID(); });
        
        std::string productName = (productIt != products.end()) ? productIt->getName() : "알 수 없음";
        
        std::cout << "- " << inv.getProductID() << " (" << productName << "): " 
                  << inv.getQuantity() << "개\n";
    }
    
    std::string productID;
    int changeAmount;
    char operation;
    
    std::cout << "\n제품 ID: ";
    std::cin >> productID;
    
    // 재고 존재 여부 확인
    auto invIt = std::find_if(inventories.begin(), inventories.end(),
        [&productID](const Inventory& inv) { return inv.getProductID() == productID; });
    
    if (invIt == inventories.end()) {
        std::cout << "해당 제품의 재고가 등록되어 있지 않습니다.\n";
        std::cout << "아무 키나 눌러주세요...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    
    std::cout << "현재 재고량: " << invIt->getQuantity() << "개\n";
    std::cout << "증가(+) 또는 차감(-) 선택 (+/-): ";
    std::cin >> operation;
    
    if (operation != '+' && operation != '-') {
        std::cout << "잘못된 입력입니다. +나 -를 입력해주세요.\n";
        std::cout << "아무 키나 눌러주세요...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    
    std::cout << "변경할 수량: ";
    std::cin >> changeAmount;
    
    if (changeAmount < 0) {
        std::cout << "변경 수량은 0 이상이어야 합니다.\n";
        std::cout << "아무 키나 눌러주세요...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    
    int newQuantity;
    if (operation == '+') {
        newQuantity = invIt->getQuantity() + changeAmount;
        if (newQuantity > invIt->getMaxStock()) {
            std::cout << "최대 재고량(" << invIt->getMaxStock() << ")을 초과할 수 없습니다.\n";
            std::cout << "아무 키나 눌러주세요...";
            std::cin.ignore();
            std::cin.get();
            return;
        }
    } else {
        newQuantity = invIt->getQuantity() - changeAmount;
        if (newQuantity < 0) {
            std::cout << "재고량이 0 미만이 될 수 없습니다.\n";
            std::cout << "아무 키나 눌러주세요...";
            std::cin.ignore();
            std::cin.get();
            return;
        }
    }
    
    // 재고 업데이트
    Inventory updatedInventory = *invIt;
    updatedInventory.setQuantity(newQuantity);
    
    if (invCtrl->updateInventory(updatedInventory)) {
        std::cout << "재고가 성공적으로 업데이트되었습니다.\n";
        std::cout << "변경 전: " << invIt->getQuantity() << "개 → 변경 후: " << newQuantity << "개\n";
        
        if (newQuantity <= invIt->getMinStock()) {
            std::cout << "⚠️  재고 부족 경고! (최소 재고량: " << invIt->getMinStock() << "개)\n";
        }
    } else {
        std::cout << "재고 업데이트에 실패했습니다.\n";
    }
    
    std::cout << "아무 키나 눌러주세요...";
    std::cin.ignore();
    std::cin.get();
} 