#include "CustomerSearchView.h"

#include <iomanip>
#include <iostream>

#include "../../controller/InventoryController.h"
#include "../../controller/ProductController.h"
#include "../../controller/ScreenController.h"

CustomerSearchView::CustomerSearchView()
{
    setErrorMessages({" ", "잘못된 입력입니다. 다시 선택하세요."});
    setTitle("제품 검색");
}

std::string CustomerSearchView::getUserChoice()
{
    std::string choice;
    std::cout << "검색하기 (0: 뒤로가기, 1: 전체보기, 제품명 검색): ";

    std::cin >> choice;
    // 입력 버퍼 비우기
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // 유효한 입력인지 확인
    if (choice == "0")
    {
        return "0";
    }
    else if (choice == "1")
    {
        return "1";
    }
    else
    {
        return choice;
    }
}

void CustomerSearchView::run()
{
    while (true)
    {
        // 화면 지우기
        clearScreen();

        // 에러 메시지 표시
        renderErrorMessages(getErrorMessages()[getShowError()]);

        // 타이틀 표시
        renderTitle(getTitle());

        // 사용자 입력 받기
        std::string choice = getUserChoice();

        if (choice == "0")
        {
            // 뒤로가기 - 스택에서 제거하여 이전 화면으로
            goBack();
            break;
        }
        else if (choice == "1")
        {
            // 전체 제품 목록 표시
            InventoryController inventoryController;
            ProductController productController;
            auto products = productController.getAllProducts();

            std::cout << "\n=== 전체 제품 목록 ===\n";

            if (products.empty())
            {
                std::cout << "등록된 제품이 없습니다.\n";
            }
            else
            {
                std::cout << std::left << std::setw(10) << "제품ID" << std::setw(20) << "제품명"
                          << std::setw(10) << "가격" << std::setw(15) << "카테고리" << std::setw(10)
                          << "재고수량" << "\n";
                std::cout
                    << "----------------------------------------------------------------------\n";

                for (const auto& product : products)
                {
                    // 해당 제품의 재고 정보 가져오기
                    Inventory* inventory =
                        inventoryController.findInventoryByProductID(product.getProductID());
                    std::string stockInfo =
                        inventory ? (std::to_string(inventory->getStock()) + "개") : "재고없음";

                    std::cout << std::left << std::setw(10) << product.getProductID()
                              << std::setw(20) << product.getName() << std::setw(10)
                              << (std::to_string(product.getPrice()) + "원") << std::setw(15)
                              << product.getCategory() << std::setw(10) << stockInfo << "\n";
                }
                std::cout << "\n총 " << products.size() << "개 제품이 등록되어 있습니다.\n";
            }

            std::cout << "\n계속하려면 Enter를 누르세요...";
            std::cin.get();
        }
        else
        {
            InventoryController inventoryController;
            ProductController productController;

            // ProductController의 검색 메서드 사용
            std::vector<Product> matchedProducts = productController.searchProductsByName(choice);

            // 검색 결과 표시
            std::cout << "\n=== 검색 결과: \"" << choice << "\" ===\n";

            if (matchedProducts.empty())
            {
                std::cout << "검색된 제품이 없습니다.\n";
            }
            else
            {
                std::cout << std::left << std::setw(10) << "제품ID" << std::setw(20) << "제품명"
                          << std::setw(10) << "가격" << std::setw(15) << "카테고리" << std::setw(10)
                          << "재고수량" << "\n";
                std::cout
                    << "----------------------------------------------------------------------\n";

                for (const auto& product : matchedProducts)
                {
                    // 해당 제품의 재고 정보 가져오기
                    Inventory* inventory =
                        inventoryController.findInventoryByProductID(product.getProductID());
                    std::string stockInfo =
                        inventory ? (std::to_string(inventory->getStock()) + "개") : "재고없음";

                    std::cout << std::left << std::setw(10) << product.getProductID()
                              << std::setw(20) << product.getName() << std::setw(10)
                              << (std::to_string(product.getPrice()) + "원") << std::setw(15)
                              << product.getCategory() << std::setw(10) << stockInfo << "\n";
                }
                std::cout << "\n총 " << matchedProducts.size() << "개 제품이 검색되었습니다.\n";
            }

            std::cout << "\n계속하려면 Enter를 누르세요...";
            std::cin.get();
        }
    }
}