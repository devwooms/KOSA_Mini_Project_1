#include "adminView.h"
#include "../viewRender.h"

adminView::adminView() {
    initialize();
}

void adminView::initialize() {
    setTitle("관리자 메뉴");
    setMenuItems({
        "제품 관리",
        "재고 관리"
    });
    setMenuActions({
        [this]() { getController()->navigateTo("product_management"); },
        [this]() { getController()->navigateTo("inventory_management"); }
    });
}

void adminView::display() {
    viewRender::render(getTitle(), getMenuItems());
} 