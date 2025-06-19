#include "AdminInventoryAddView.h"

#include <iostream>

#include "../../controller/InventoryController.h"
#include "../../controller/ScreenController.h"

AdminInventoryAddView::AdminInventoryAddView()
{
    setErrorMessages({
        " ",
        "이미 등록된 제품ID입니다.",
    });
    setTitle("재고 입력");
}

void AdminInventoryAddView::run()
{
    std::string productID;
    int stock;

    InventoryController inventoryController;

    while (true)
    {
        // 화면 지우기
        clearScreen();

        // 에러 메시지 표시
        renderErrorMessages(getErrorMessages()[getShowError()]);

        // 타이틀 표시
        renderTitle(getTitle());

        std::cout << "제품ID: ";
        std::cin >> productID;

        if (productID == "0")
        {
            goBack();
            break;
        }

        if (inventoryController.findInventoryByProductID(productID) != nullptr)
        {
            setShowError(1);
            break;
        }
        std::cout << "재고수량: ";
        std::cin >> stock;

        inventoryController.addInventory(productID, stock);

        std::cout << "재고 등록이 완료되었습니다." << std::endl;

        std::cout << "뒤로가려면 아무키나 누르세요...";
        std::cin.get();

        goBack();
        break;
    }
}