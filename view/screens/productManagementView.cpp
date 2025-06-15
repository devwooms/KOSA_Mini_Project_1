#include "productManagementView.h"
#include "../viewRender.h"

productManagementView::productManagementView() {
    initialize();
}

void productManagementView::initialize() {
    setTitle("제품 관리");
    setMenuItems({
        "제품 조회",
        "제품 입력",
        "제품 수정",
        "제품 삭제"
    });
    setMenuActions({
        [this]() { getController()->navigateTo("product_list"); },
        [this]() { getController()->navigateTo("product_add"); },
        [this]() { getController()->navigateTo("product_edit"); },
        [this]() { getController()->navigateTo("product_delete"); }
    });
}

void productManagementView::display() {
    viewRender::render(getTitle(), getMenuItems());
} 