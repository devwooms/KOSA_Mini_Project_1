#include "productAddView.h"
#include "../viewRender.h"

productAddView::productAddView() {
    prodCtrl = std::make_shared<productController>();
    initialize();
}

void productAddView::initialize() {
    setTitle("제품 입력");
    setMenuItems({
        "뒤로가기"
    });
    setMenuActions({
        [this]() { getController()->goBack(); }
    });
}

void productAddView::display() {
    addNewProduct();
    std::cout << "\n";
    viewRender::render(getTitle(), getMenuItems());
}

void productAddView::addNewProduct() {
    std::cout << "\n=== 새 제품 입력 ===\n";
    
    std::string productID, name, category;
    int price;
    
    std::cout << "제품 ID: ";
    std::cin >> productID;
    
    // 중복 제품 ID 확인
    auto products = prodCtrl->getAllProducts();
    auto productIt = std::find_if(products.begin(), products.end(),
        [&productID](const product& p) { return p.getProductID() == productID; });
    
    if (productIt != products.end()) {
        std::cout << "이미 존재하는 제품 ID입니다.\n";
        std::cout << "아무 키나 눌러주세요...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    
    std::cin.ignore(); // 버퍼 클리어
    std::cout << "제품명: ";
    std::getline(std::cin, name);
    
    std::cout << "가격: ";
    std::cin >> price;
    
    if (price < 0) {
        std::cout << "가격은 0 이상이어야 합니다.\n";
        std::cout << "아무 키나 눌러주세요...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    
    std::cin.ignore(); // 버퍼 클리어
    std::cout << "카테고리: ";
    std::getline(std::cin, category);
    
    // 입력 확인
    std::cout << "\n=== 입력 정보 확인 ===\n";
    std::cout << "제품 ID: " << productID << "\n";
    std::cout << "제품명: " << name << "\n";
    std::cout << "가격: " << price << "원\n";
    std::cout << "카테고리: " << category << "\n";
    
    char confirm;
    std::cout << "\n위 정보로 제품을 등록하시겠습니까? (y/n): ";
    std::cin >> confirm;
    
    if (confirm == 'y' || confirm == 'Y') {
        // 새 제품 생성 및 추가
        product newProduct(0, productID, name, price, category);
        
        if (prodCtrl->addProduct(newProduct)) {
            std::cout << "제품이 성공적으로 등록되었습니다.\n";
        } else {
            std::cout << "제품 등록에 실패했습니다.\n";
        }
    } else {
        std::cout << "제품 등록이 취소되었습니다.\n";
    }
    
    std::cout << "아무 키나 눌러주세요...";
    std::cin.ignore();
    std::cin.get();
} 