#include "productEditView.h"
#include "../viewRender.h"

productEditView::productEditView() {
    prodCtrl = std::make_shared<productController>();
    initialize();
}

void productEditView::initialize() {
    setTitle("제품 수정");
    setMenuItems({
        "뒤로가기"
    });
    setMenuActions({
        [this]() { getController()->goBack(); }
    });
}

void productEditView::display() {
    editProduct();
    std::cout << "\n";
    viewRender::render(getTitle(), getMenuItems());
}

void productEditView::editProduct() {
    std::cout << "\n=== 제품 수정 ===\n";
    
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
    std::cout << "\n수정할 제품 ID: ";
    std::cin >> productID;
    
    // 제품 존재 여부 확인
    auto productIt = std::find_if(products.begin(), products.end(),
        [&productID](const product& p) { return p.getProductID() == productID; });
    
    if (productIt == products.end()) {
        std::cout << "존재하지 않는 제품 ID입니다.\n";
        std::cout << "아무 키나 눌러주세요...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    
    // 현재 정보 표시
    std::cout << "\n=== 현재 제품 정보 ===\n";
    std::cout << "제품 ID: " << productIt->getProductID() << "\n";
    std::cout << "제품명: " << productIt->getName() << "\n";
    std::cout << "가격: " << productIt->getPrice() << "원\n";
    std::cout << "카테고리: " << productIt->getCategory() << "\n";
    
    // 수정할 정보 입력
    std::string newName, newCategory;
    int newPrice;
    
    std::cin.ignore(); // 버퍼 클리어
    std::cout << "\n새 제품명 (현재: " << productIt->getName() << "): ";
    std::getline(std::cin, newName);
    if (newName.empty()) {
        newName = productIt->getName();
    }
    
    std::cout << "새 가격 (현재: " << productIt->getPrice() << "원): ";
    std::string priceInput;
    std::getline(std::cin, priceInput);
    if (priceInput.empty()) {
        newPrice = productIt->getPrice();
    } else {
        try {
            newPrice = std::stoi(priceInput);
            if (newPrice < 0) {
                std::cout << "가격은 0 이상이어야 합니다.\n";
                std::cout << "아무 키나 눌러주세요...";
                std::cin.get();
                return;
            }
        } catch (const std::exception&) {
            std::cout << "잘못된 가격 형식입니다.\n";
            std::cout << "아무 키나 눌러주세요...";
            std::cin.get();
            return;
        }
    }
    
    std::cout << "새 카테고리 (현재: " << productIt->getCategory() << "): ";
    std::getline(std::cin, newCategory);
    if (newCategory.empty()) {
        newCategory = productIt->getCategory();
    }
    
    // 수정 정보 확인
    std::cout << "\n=== 수정 정보 확인 ===\n";
    std::cout << "제품 ID: " << productIt->getProductID() << "\n";
    std::cout << "제품명: " << productIt->getName() << " → " << newName << "\n";
    std::cout << "가격: " << productIt->getPrice() << "원 → " << newPrice << "원\n";
    std::cout << "카테고리: " << productIt->getCategory() << " → " << newCategory << "\n";
    
    char confirm;
    std::cout << "\n위 정보로 제품을 수정하시겠습니까? (y/n): ";
    std::cin >> confirm;
    
    if (confirm == 'y' || confirm == 'Y') {
        // 제품 정보 업데이트
        product updatedProduct = *productIt;
        updatedProduct.setName(newName);
        updatedProduct.setPrice(newPrice);
        updatedProduct.setCategory(newCategory);
        
        if (prodCtrl->updateProduct(updatedProduct)) {
            std::cout << "제품 정보가 성공적으로 수정되었습니다.\n";
        } else {
            std::cout << "제품 정보 수정에 실패했습니다.\n";
        }
    } else {
        std::cout << "제품 수정이 취소되었습니다.\n";
    }
    
    std::cout << "아무 키나 눌러주세요...";
    std::cin.ignore();
    std::cin.get();
} 