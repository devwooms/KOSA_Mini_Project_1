#include "screenController.h"
#include "../view/baseScreenView.h"
#include "../view/screens/TestView1.hpp"
#include "../view/screens/TestView2.hpp"
#include "../view/screens/TestView3.hpp"
#include <iostream>

screenController::screenController() {
    // 테스트 화면들 등록
    registerScreen("test1", std::make_shared<TestView1>());
    registerScreen("test2", std::make_shared<TestView2>());
    registerScreen("test3", std::make_shared<TestView3>());
}

void screenController::run() {
    // 초기 화면으로 test1을 설정
    navigateTo("test1");

    while (!screenStack.empty()) {
        auto currentScreen = screenStack.top();
        
        // 현재 화면 표시
        currentScreen->display();
        
        // 사용자 입력 처리
        int choice = currentScreen->getInput();
        
        if (choice == 0) {
            goBack();
        } else if (choice > 0 && choice <= currentScreen->getMenuItems().size()) {
            // 메뉴 액션 실행
            currentScreen->getMenuAction()();
        }
    }
}

void screenController::navigateTo(const std::string& screenName) {
    if (screens.find(screenName) != screens.end()) {
        auto screen = screens[screenName];
        screen->setController(this);
        screenStack.push(screen);
    }
}

void screenController::goBack() {
    if (!screenStack.empty()) {
        screenStack.pop();
    }
}

void screenController::registerScreen(const std::string& name, std::shared_ptr<baseScreenView> screen) {
    screens[name] = screen;
    screen->setController(this);
} 