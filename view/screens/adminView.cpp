#include "AdminView.h"
#include "../../controller/ScreenController.h"
#include "ProductManagementView.h"
#include "InventoryManagementView.h"

AdminView::AdminView() {
    setTitle("관리자 메뉴");
    setMenuItems({
        "제품 관리",
        "재고 관리"
    });
    setMenuActions({
        [this]() { 
            auto screen = std::make_shared<ProductManagementView>();
            getController()->pushScreen(screen);
        },
        [this]() { 
            auto screen = std::make_shared<InventoryManagementView>();
            getController()->pushScreen(screen);
        }
    });
}