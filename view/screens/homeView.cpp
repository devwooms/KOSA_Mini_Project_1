#include "homeView.h"
#include "../viewRender.h"

homeView::homeView() {
    initialize();
}

void homeView::initialize() {
    setTitle("KOSA 편의점");
    setMenuItems({
        "로그인",
        "회원가입",
    });
    setMenuActions({
        [this]() { getController()->navigateTo("login"); },
        [this]() { getController()->navigateTo("signup"); }
    });
}

void homeView::display() {
    viewRender::render(getTitle(), getMenuItems());
} 