#include "AdminProductDeleteView.h"

#include <iostream>

#include "../../controller/ScreenController.h"
#include "../../controller/ProductController.h"

AdminProductDeleteView::AdminProductDeleteView()
{
    setErrorMessages({
        " ",
        "잘못된 입력입니다. 다시 선택하세요.",
    });
    setTitle("제품 삭제");
}


void AdminProductDeleteView::run()
{
    ProductController productController;

    while (true)
    {
        // 화면 지우기
        clearScreen();

        // 에러 메시지 표시
        renderErrorMessages(getErrorMessages()[getShowError()]);

        // 타이틀 표시
        renderTitle(getTitle());

        std::cout << "삭제 할 제품ID (0: 뒤로가기): ";
        std::string productID;
        std::cin >> productID;
        if (productID == "0")
        {
            goBack();
            break;
        }

        Product *product = productController.findProductByProductID(productID);
        if (product == nullptr)
        {
            setShowError(1);
            continue;
        }

        std::cout << "\n=== 삭제 할 제품 정보 ===\n";
        std::cout << std::left << std::setw(8) << "제품ID\t\t" << std::setw(15) << "이름\t"
                    << std::setw(8) << "가격\t" << std::setw(10) << "카테고리\n";
        std::cout << "-----------------------------------------------------------\n";
        std::cout << std::left << std::setw(8) << product->getProductID() << "\t"
                  << std::setw(15) << product->getName() << "\t"
                  << std::setw(8) << (std::to_string(product->getPrice()) + "원") << "\t"
                  << std::setw(10) << product->getCategory() << "\n";

        std::cout << "\n이 제품이 맞습니까? (0: 뒤로가기, 1: 삭제): ";
        std::string choice;
        std::cin >> choice;
        if (choice == "0")
        {
            goBack();
            break;
        }
        else if (choice == "1")
        {
            productController.deleteProduct(productID);
            std::cout << "제품이 삭제되었습니다." << std::endl;
            std::cout << "계속하려면 Enter를 누르세요...";
            std::cin.get();
            goBack();
            break;
        }
    }
}