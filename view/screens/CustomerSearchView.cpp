#include "CustomerSearchView.h"

#include <iomanip>
#include <iostream>

#include "../../controller/InventoryController.h"
#include "../../controller/ScreenController.h"

CustomerSearchView::CustomerSearchView()
{
    setErrorMessages({" ", "잘못된 입력입니다. 다시 선택하세요."});
    setTitle("제품 검색");
}

int CustomerSearchView::getUserChoice()
{
    std::string choice;
    std::cout << "검색하기 (0: 뒤로가기, 1: 전체보기): ";

    std::cin >> choice;
    // 입력 버퍼 비우기
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // 유효한 입력인지 확인
    if (choice == "0")
    {
        return 0;
    }
    else if (choice == "1")
    {
        return 1;
    }
    else
    {
        // 잘못된 입력의 경우 -1 반환
        return -1;
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
        int choice = getUserChoice();

        // 선택 처리
        if (choice == -1)
        {
            // 잘못된 입력 - 에러 플래그 설정하고 다시 루프
            setShowError(1);
            continue;
        }
        else if (choice == 0)
        {
            // 뒤로가기 - 스택에서 제거하여 이전 화면으로
            goBack();
            break;
        }
        else if (choice == 1)
        {
            // 전체 인벤토리 목록 표시
            InventoryController inventoryController;
            auto inventories = inventoryController.getAllInventories();

            std::cout << "\n=== 전체 재고 목록 ===\n";
            std::cout << std::left << std::setw(10) << "제품ID" << std::setw(10) << "재고수량\n";
            std::cout << "------------------------\n";

            if (inventories.empty())
            {
                std::cout << "등록된 재고가 없습니다.\n";
            }
            else
            {
                for (const auto& inventory : inventories)
                {
                    std::cout << std::left << std::setw(10) << inventory.getProductID()
                              << std::setw(10) << (std::to_string(inventory.getStock()) + "개")
                              << "\n";
                }
                std::cout << "\n총 " << inventories.size() << "개 제품의 재고 정보\n";
            }

            std::cout << "\n계속하려면 Enter를 누르세요...";
            std::cin.get();
        }
        else
        {
            // 잘못된 입력 - 에러 플래그 설정하고 다시 루프
            setShowError(1);
            continue;
        }
    }
}