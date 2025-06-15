#include "InventoryListView.h"
using namespace std;

InventoryListView::InventoryListView() {
    invCtrl = std::make_shared<InventoryController>();
    prodCtrl = std::make_shared<ProductController>();
    setTitle("재고 조회");
    setMenuItems({
        "뒤로가기"
    });
    setMenuActions({
        [this]() { goBack(); }
    });
}

void InventoryListView::showInventoryList() {
    std::cout << "\n=== 재고 현황 ===\n";
    std::cout << std::left << std::setw(10) << "제품ID" 
              << std::setw(15) << "제품명" 
              << std::setw(10) << "현재고" 
              << std::setw(10) << "최소재고" 
              << std::setw(10) << "최대재고" 
              << std::setw(10) << "가격" << "\n";
    std::cout << std::string(65, '-') << "\n";

    auto inventories = invCtrl->getAllInventories();
    auto products = prodCtrl->getAllProducts();

    for (const auto& inv : inventories) {
        // 해당 제품 정보 찾기
        auto productIt = std::find_if(products.begin(), products.end(),
            [&inv](const Product& p) { return p.getProductID() == inv.getProductID(); });
        
        std::string productName = (productIt != products.end()) ? productIt->getName() : "알 수 없음";
        int price = (productIt != products.end()) ? productIt->getPrice() : 0;
        
        std::cout << std::left << std::setw(10) << inv.getProductID()
                  << std::setw(15) << productName
                  << std::setw(10) << inv.getQuantity()
                  << std::setw(10) << inv.getMinStock()
                  << std::setw(10) << inv.getMaxStock()
                  << std::setw(10) << price << "원\n";
        
        // 재고 부족 경고
        if (inv.getQuantity() <= inv.getMinStock()) {
            std::cout << "  ⚠️  재고 부족 경고!\n";
        }
    }
    
    std::cout << "\n아무 키나 눌러주세요...";
    std::cin.ignore();
    std::cin.get();
} 