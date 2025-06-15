#include "TestView2.h"

TestView2::TestView2() {
    initialize();
}

void TestView2::initialize() {
    setTitle("테스트 화면 2");
    setMenuItems({
        "테스트 화면 1로 이동",
        "테스트 화면 3으로 이동"
    });
    setMenuActions({
        [this]() { getController()->navigateTo("test1"); },
        [this]() { getController()->navigateTo("test3"); }
    });
}

void TestView2::display() {

}

int TestView2::getInput() {

} 