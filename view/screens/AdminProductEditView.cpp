#include "AdminProductEditView.h"

#include <iomanip>
#include <iostream>

#include "../../controller/ProductController.h"
#include "../../controller/ScreenController.h"

AdminProductEditView::AdminProductEditView()
{
    setErrorMessages({
        " ",
        "존재하지 않는 제품ID입니다.",
    });
    setTitle("제품 수정");
}

void AdminProductEditView::run()
{
    std::string productID;

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

        Product* product = productController.findProductByProductID(productID);
        if (product == nullptr)
        {
            setShowError(1);
            continue;
        }

        std::cout << "\n=== 현재 제품 정보 ===\n";
        std::cout << std::left << std::setw(8) << "제품ID\t\t" << std::setw(15) << "이름\t"
                  << std::setw(8) << "가격\t" << std::setw(10) << "카테고리\n";
        std::cout << "-----------------------------------------------------------\n";
        std::cout << std::left << std::setw(8) << product->getProductID() << "\t" << std::setw(15)
                  << product->getName() << "\t" << std::setw(8)
                  << (std::to_string(product->getPrice()) + "원") << "\t" << std::setw(10)
                  << product->getCategory() << "\n";

        std::cout << "\n수정할 정보를 입력하세요 (0: 뒤로가기, 1: 제품명, 2: 가격, 3: 카테고리, 4: "
                     "설명): ";
        std::string choice;
        std::cin >> choice;

        if (choice == "0")
        {
            goBack();
            break;
        }
        else if (choice == "1")
        {
            std::cout << "새 제품명 (0: 뒤로가기): ";
            std::string name;
            std::cin >> name;
            if (name == "0")
            {
                continue;  // 뒤로가기 - 제품 선택으로 돌아감
            }
            product->setName(name);
        }
        else if (choice == "2")
        {
            std::cout << "새 가격 (0: 뒤로가기): ";
            int price;
            std::cin >> price;
            if (price == 0)
            {
                continue;  // 뒤로가기 - 제품 선택으로 돌아감
            }
            product->setPrice(price);
        }
        else if (choice == "3")
        {
            std::cout << "새 카테고리 (0: 뒤로가기): ";
            std::string category;
            std::cin >> category;
            if (category == "0")
            {
                continue;  // 뒤로가기 - 제품 선택으로 돌아감
            }
            product->setCategory(category);
        }
        else if (choice == "4")
        {
            std::cout << "새 설명 (0: 뒤로가기): ";
            std::string description;
            std::cin >> description;
            if (description == "0")
            {
                continue;  // 뒤로가기 - 제품 선택으로 돌아감
            }
            product->setDescription(description);
        }
        else
        {
            continue;  // 잘못된 선택 - 다시 선택하게 함
        }

        std::cout << "\n=== 수정된 제품 정보 ===\n";
        std::cout << std::left << std::setw(8) << "제품ID\t\t" << std::setw(15) << "이름\t"
                  << std::setw(8) << "가격\t" << std::setw(10) << "카테고리\n";
        std::cout << "-----------------------------------------------------------\n";
        std::cout << std::left << std::setw(8) << product->getProductID() << "\t" << std::setw(15)
                  << product->getName() << "\t" << std::setw(8)
                  << (std::to_string(product->getPrice()) + "원") << "\t" << std::setw(10)
                  << product->getCategory() << "\n";

        std::cout << "\n수정을 저장하시겠습니까? (0: 취소, 1: 저장): ";
        std::string choice2;
        std::cin >> choice2;

        if (choice2 == "0")
        {
            continue;  // 취소 - 제품 선택으로 돌아감
        }
        else if (choice2 == "1")
        {
            bool success = productController.updateProduct(
                product->getProductID(), product->getName(), product->getPrice(),
                product->getCategory(), product->getDescription());

            if (success)
            {
                std::cout << "제품 정보가 성공적으로 수정되었습니다!" << std::endl;
            }
            else
            {
                std::cout << "제품 수정에 실패했습니다." << std::endl;
            }
        }

        std::cout << "\n계속하려면 Enter를 누르세요...";
        std::cin.ignore();
        std::cin.get();

        continue;  // 다시 제품 선택으로 돌아감
    }
}