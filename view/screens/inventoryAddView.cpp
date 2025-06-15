#include "InventoryAddView.h"

using namespace std;

InventoryAddView::InventoryAddView() {
    invCtrl = std::make_shared<InventoryController>();
    prodCtrl = std::make_shared<ProductController>();
    setTitle("재고 입력");
    setMenuItems({
        "뒤로가기"
    });
    setMenuActions({
        [this]() { goBack(); }
    });
}

void InventoryAddView::addNewInventory() {
    std::cout << "\n=== 새 재고 입력 ===\n";
    
    // 기존 제품 목록 표시
    auto products = prodCtrl->getAllProducts();
    std::cout << "\n등록된 제품 목록:\n";
    for (const auto& product : products) {
        std::cout << "- " << product.getProductID() << ": " << product.getName() << "\n";
    }
    
    std::string productID;
    int quantity, minStock, maxStock;
    
    std::cout << "\n제품 ID: ";
    std::cin >> productID;
    
    // 제품 존재 여부 확인
    auto productIt = std::find_if(products.begin(), products.end(),
        [&productID](const Product& p) { return p.getProductID() == productID; });
    
    if (productIt == products.end()) {
        std::cout << "존재하지 않는 제품 ID입니다.\n";
        std::cout << "아무 키나 눌러주세요...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    
    // 이미 재고가 등록된 제품인지 확인
    auto inventories = invCtrl->getAllInventories();
    auto invIt = std::find_if(inventories.begin(), inventories.end(),
        [&productID](const Inventory& inv) { return inv.getProductID() == productID; });
    
    if (invIt != inventories.end()) {
        std::cout << "이미 재고가 등록된 제품입니다. 재고 수정 메뉴를 이용해주세요.\n";
        std::cout << "아무 키나 눌러주세요...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    
    std::cout << "초기 재고량: ";
    std::cin >> quantity;
    
    std::cout << "최소 재고량: ";
    std::cin >> minStock;
    
    std::cout << "최대 재고량: ";
    std::cin >> maxStock;
    
    if (quantity < 0 || minStock < 0 || maxStock < 0) {
        std::cout << "재고량은 0 이상이어야 합니다.\n";
        std::cout << "아무 키나 눌러주세요...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    
    if (minStock > maxStock) {
        std::cout << "최소 재고량이 최대 재고량보다 클 수 없습니다.\n";
        std::cout << "아무 키나 눌러주세요...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    
    // 새 재고 생성 및 추가
    Inventory newInventory(0, productID, quantity, minStock, maxStock);
    
    if (invCtrl->addInventory(newInventory)) {
        std::cout << "재고가 성공적으로 등록되었습니다.\n";
    } else {
        std::cout << "재고 등록에 실패했습니다.\n";
    }
    
    std::cout << "아무 키나 눌러주세요...";
    std::cin.ignore();
    std::cin.get();
} 