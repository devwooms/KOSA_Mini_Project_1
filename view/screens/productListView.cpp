#include "productListView.h"
#include "../viewRender.h"

productListView::productListView() {
    prodCtrl = std::make_shared<productController>();
    initialize();
}

void productListView::initialize() {
    setTitle("제품 조회");
    setMenuItems({
        "뒤로가기"
    });
    setMenuActions({
        [this]() { getController()->goBack(); }
    });
}

void productListView::display() {
    showProductList();
    std::cout << "\n";
    viewRender::render(getTitle(), getMenuItems());
}

void productListView::showProductList() {
    std::cout << "\n=== 제품 목록 ===\n";
    std::cout << std::left << std::setw(10) << "제품ID" 
              << std::setw(20) << "제품명" 
              << std::setw(10) << "가격" 
              << std::setw(15) << "카테고리" << "\n";
    std::cout << std::string(55, '-') << "\n";

    auto products = prodCtrl->getAllProducts();
    
    if (products.empty()) {
        std::cout << "등록된 제품이 없습니다.\n";
    } else {
        for (const auto& product : products) {
            std::cout << std::left << std::setw(10) << product.getProductID()
                      << std::setw(20) << product.getName()
                      << std::setw(10) << (std::to_string(product.getPrice()) + "원")
                      << std::setw(15) << product.getCategory() << "\n";
        }
    }
    
    std::cout << "\n총 " << products.size() << "개의 제품이 등록되어 있습니다.\n";
    std::cout << "\n아무 키나 눌러주세요...";
    std::cin.ignore();
    std::cin.get();
} 