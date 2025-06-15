#include "TestView1.h"
#include "../viewRender.h"

TestView1::TestView1() {
    initialize();
}

void TestView1::initialize() {
    setTitle("테스트 화면 1");
    setMenuItems({
        "테스트 화면 2로 이동",
        "테스트 화면 3으로 이동"
    });
    setMenuActions({
        [this]() { getController()->navigateTo("test2"); },
        [this]() { getController()->navigateTo("test3"); }
    });
}

void TestView1::display() {
    viewRender::render(getTitle(), getMenuItems());
}
