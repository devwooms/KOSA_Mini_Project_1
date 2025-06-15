#include "consumerView.h"
#include "../viewRender.h"

consumerView::consumerView() {
    initialize();
}

void consumerView::initialize() {
    setTitle("소비자 메뉴");
    setMenuItems({
        "제품 검색"
    });
    setMenuActions({
        [this]() { getController()->navigateTo("product_search"); }
    });
}

void consumerView::display() {
    viewRender::render(getTitle(), getMenuItems());
} 