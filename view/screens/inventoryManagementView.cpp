#include "inventoryManagementView.h"
#include "../viewRender.h"

inventoryManagementView::inventoryManagementView() {
    initialize();
}

void inventoryManagementView::initialize() {
    setTitle("재고 관리");
    setMenuItems({
        "재고 조회",
        "재고 입력",
        "재고 증가/차감"
    });
    setMenuActions({
        [this]() { getController()->navigateTo("inventory_list"); },
        [this]() { getController()->navigateTo("inventory_add"); },
        [this]() { getController()->navigateTo("inventory_modify"); }
    });
}

void inventoryManagementView::display() {
    viewRender::render(getTitle(), getMenuItems());
} 