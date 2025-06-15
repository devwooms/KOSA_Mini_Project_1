#include "loginView.h"
#include "../viewRender.h"

loginView::loginView() {
    initialize();
}

void loginView::initialize() {
    setTitle("로그인");
    setMenuItems({
        "소비자",
        "관리자"
    });
    setMenuActions({
        [this]() { getController()->navigateTo("consumer"); },
        [this]() { getController()->navigateTo("admin"); }
    });
}

void loginView::display() {
    viewRender::render(getTitle(), getMenuItems());
} 