#include "TestView3.h"
#include "../viewRender.h"

TestView3::TestView3() {
    initialize();
}

void TestView3::initialize() {
    setTitle("테스트 화면 3");
    setMenuItems({
        "테스트 화면 1로 이동",
        "테스트 화면 2로 이동"
    });
    setMenuActions({
        [this]() { getController()->navigateTo("test1"); },
        [this]() { getController()->navigateTo("test2"); }
    });
}

void TestView3::display() {
    viewRender::render(getTitle(), getMenuItems());
} 