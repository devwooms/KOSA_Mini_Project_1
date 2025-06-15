#include "AdminInventoryModifyView.h"

#include <iostream>

#include "../../controller/ScreenController.h"
#include "../../controller/InventoryController.h"

AdminInventoryModifyView::AdminInventoryModifyView()
{
    setErrorMessages({
        " ",
        "잘못된 입력입니다. 다시 선택하세요.",
    });
    setTitle("재고 증가/차감");
}


void AdminInventoryModifyView::run()
{
    std::string productID;
    int stock;
    int modifyStock;

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
            std::cout << "뒤로가려면 아무키나 누르세요...";
            std::cin.get();
            break;
        }
        else
        {
            for (const auto& inventory : inventories)
            {
                std::cout << std::left << std::setw(10) << inventory.getProductID() << std::setw(10)
                          << (std::to_string(inventory.getStock()) + "개") << "\n";
            }
        }

        std::cout << "재고 증가/차감할 제품ID (0: 뒤로가기): ";
        std::cin >> productID;

        if (productID == "0")
        {
            goBack();
            break;
        }

        if (inventoryController.findInventoryByProductID(productID) == nullptr)
        {
            setShowError(1);
            break;
        } else {
            stock = inventoryController.getStock(productID);
        }

        std::cout << "재고 증가/차감 수량: ";
        std::cin >> modifyStock;

        inventoryController.updateInventory(productID, stock + modifyStock);

        std::cout << "재고 증가/차감이 완료되었습니다." << std::endl;
        std::cout << "뒤로가려면 아무키나 누르세요...";
        std::cin.get();
        break;
    }
}