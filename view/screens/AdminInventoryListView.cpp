#include "AdminInventoryListView.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../../controller/InventoryController.h"
#include "../../controller/ScreenController.h"

AdminInventoryListView::AdminInventoryListView()
{
    setErrorMessages({
        " ",
        "잘못된 입력입니다. 다시 선택하세요.",
    });
    setTitle("재고 조회");
}

void AdminInventoryListView::run()
{
    InventoryController inventoryController;
    auto inventories = inventoryController.getAllInventories();

    while (true)
    {
        // 화면 지우기
        clearScreen();

        // 에러 메시지 표시
        renderErrorMessages(getErrorMessages()[getShowError()]);

        // 타이틀 표시
        renderTitle(getTitle());

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
                std::cout << std::left << std::setw(10) << inventory.getProductID() << std::setw(10)
                          << (std::to_string(inventory.getStock()) + "개") << "\n";
            }
            std::cout << "\n총 " << inventories.size() << "개 제품의 재고 정보\n";
        }

        // 뒤로가기 - 스택에서 제거하여 이전 화면으로
        goBack();
        break;
    }
}