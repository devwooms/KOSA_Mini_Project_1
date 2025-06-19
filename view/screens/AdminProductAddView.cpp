#include "AdminProductAddView.h"

#include <iostream>

#include "../../controller/ProductController.h"
#include "../../controller/ScreenController.h"

AdminProductAddView::AdminProductAddView()
{
    setErrorMessages({
        " ",
        "이미 존재하는 제품ID입니다.",
        "잘못된 입력입니다. 다시 선택하세요.",
    });
    setTitle("제품 입력");
}

void AdminProductAddView::run()
{
    std::string productID;
    std::string name;
    int price;
    std::string category;
    std::string description;

    ProductController productController;

    while (true)
    {
        // 화면 지우기
        clearScreen();

        // 에러 메시지 표시
        renderErrorMessages(getErrorMessages()[getShowError()]);

        // 타이틀 표시
        renderTitle(getTitle());

        std::cout << "제품ID (0: 뒤로가기): ";
        std::cin >> productID;

        if (productID == "0")
        {
            goBack();
            break;
        }

        // 제품ID 중복 체크 - ProductController 메서드 활용
        if (productController.findProductByProductID(productID) != nullptr)
        {
            setShowError(1);
            continue;
        }

        std::cout << "제품명 (0: 뒤로가기): ";
        std::cin >> name;
        if (name == "0")
        {
            goBack();
            break;
        }
        std::cout << "가격 (0: 뒤로가기): ";
        std::cin >> price;
        if (price == 0)
        {
            goBack();
            break;
        }
        std::cout << "카테고리 (0: 뒤로가기): ";
        std::cin >> category;
        if (category == "0")
        {
            goBack();
            break;
        }
        std::cout << "설명 (0: 뒤로가기): ";
        std::cin >> description;
        if (description == "0")
        {
            goBack();
            break;
        }

        if (productController.addProduct(productID, name, price, category, description))
        {
            std::cout << "제품이 추가되었습니다." << std::endl;
        }

        std::cout << "계속하려면 Enter를 누르세요...";
        std::cin.ignore();
        std::cin.get();

        goBack();
        break;
    }
}