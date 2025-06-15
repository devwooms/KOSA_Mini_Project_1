#include "ScreenController.h"
#include "../view/screens/HomeView.h"
#include <iostream>

// ============================================================================
// 스택 관리 메서드들
// ============================================================================

// 화면 스택에 화면 추가
void ScreenController::pushScreen(std::shared_ptr<BaseScreenView> screen) {
    if (screen) {
        screen->setController(this);
        screenStack.push(screen);
    }
}

// 화면 스택에서 화면 제거
void ScreenController::popScreen() {
    if (!screenStack.empty()) {
        screenStack.pop();
    }
}

// 화면 스택에서 화면 교체
void ScreenController::replaceScreen(std::shared_ptr<BaseScreenView> screen) {
    if (!screenStack.empty()) {
        screenStack.pop();
    }
    pushScreen(screen);
}

// 화면 스택 초기화
void ScreenController::clearStack() {
    while (!screenStack.empty()) {
        screenStack.pop();
    }
}

// ============================================================================
// 현재 화면 실행
// ============================================================================

// 화면 실행
void ScreenController::run() {
    // 초기 화면 설정
    if (screenStack.empty()) {
        pushScreen(std::make_shared<HomeView>());
    }
    
    bool running = true;
    while (running && !screenStack.empty()) {
        auto currentScreen = screenStack.top();
        
        // 각 화면의 run() 메서드 호출
        currentScreen->run();
        
        // 스택이 비었으면 종료
        if (screenStack.empty()) {
            running = false;
        }
    }
}

// ============================================================================
// 접근자 메서드들
// ============================================================================

// 현재 화면 반환
std::shared_ptr<BaseScreenView> ScreenController::getCurrentScreen() const {
    return screenStack.empty() ? nullptr : screenStack.top();
}

// 화면 스택 비었는지 확인
bool ScreenController::hasScreens() const {
    return !screenStack.empty();
}

// 화면 스택 크기 반환
size_t ScreenController::getStackSize() const {
    return screenStack.size();
}