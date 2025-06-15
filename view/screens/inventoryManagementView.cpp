#include "InventoryManagementView.h"

InventoryManagementView::InventoryManagementView() {
    setTitle("재고 관리");
    setMenuItems({
        "재고 조회",
        "재고 입력",
        "재고 증가/차감"    
    });
    setMenuActions({

    });
} 