#include "ProductDeleteView.h"


ProductDeleteView::ProductDeleteView() {
    prodCtrl = std::make_shared<ProductController>();
    invCtrl = std::make_shared<InventoryController>();
}


void ProductDeleteView::deleteProduct() {
    std::cout << "\n=== 제품 삭제 ===\n";
    
    auto products = prodCtrl->getAllProducts();
    
    if (products.empty()) {
        std::cout << "등록된 제품이 없습니다.\n";
        std::cout << "아무 키나 눌러주세요...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    
    // 현재 제품 목록 표시
    std::cout << "\n현재 등록된 제품 목록:\n";
    for (const auto& product : products) {
        std::cout << "- " << product.getProductID() << ": " << product.getName() 
                  << " (" << product.getPrice() << "원, " << product.getCategory() << ")\n";
    }
    
    std::string productID;
    std::cout << "\n삭제할 제품 ID: ";
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
    
    // 재고 존재 여부 확인
    auto inventories = invCtrl->getAllInventories();
    auto invIt = std::find_if(inventories.begin(), inventories.end(),
        [&productID](const Inventory& inv) { return inv.getProductID() == productID; });
    
    if (invIt != inventories.end()) {
        std::cout << "⚠️  경고: 이 제품에 대한 재고가 존재합니다.\n";
        std::cout << "현재 재고량: " << invIt->getQuantity() << "개\n";
        std::cout << "제품을 삭제하면 관련 재고 정보도 함께 삭제됩니다.\n";
    }
    
    // 삭제할 제품 정보 표시
    std::cout << "\n=== 삭제할 제품 정보 ===\n";
    std::cout << "제품 ID: " << productIt->getProductID() << "\n";
    std::cout << "제품명: " << productIt->getName() << "\n";
    std::cout << "가격: " << productIt->getPrice() << "원\n";
    std::cout << "카테고리: " << productIt->getCategory() << "\n";
    
    char confirm;
    std::cout << "\n정말로 이 제품을 삭제하시겠습니까? (y/n): ";
    std::cin >> confirm;
    
    if (confirm == 'y' || confirm == 'Y') {
        bool success = true;
        
        // 관련 재고가 있다면 먼저 삭제
        if (invIt != inventories.end()) {
            if (!invCtrl->deleteInventory(productID)) {
                std::cout << "재고 정보 삭제에 실패했습니다.\n";
                success = false;
            }
        }
        
        // 제품 삭제
        if (success && prodCtrl->deleteProduct(productID)) {
            std::cout << "제품이 성공적으로 삭제되었습니다.\n";
            if (invIt != inventories.end()) {
                std::cout << "관련 재고 정보도 함께 삭제되었습니다.\n";
            }
        } else {
            std::cout << "제품 삭제에 실패했습니다.\n";
        }
    } else {
        std::cout << "제품 삭제가 취소되었습니다.\n";
    }
    
    std::cout << "아무 키나 눌러주세요...";
    std::cin.ignore();
    std::cin.get();
} 