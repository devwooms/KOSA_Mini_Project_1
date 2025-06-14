#include "screenController.h"
#include <iostream>
#include <memory>

screenController::screenController() {
    // 초기 화면 설정
    navigateTo("test1");
}

void screenController::run() {
    while (!viewStack.empty()) {
        auto currentView = viewStack.top();
        currentView->display();
        
        int input = currentView->getInput();
        // 입력이 -1이면 뒤로가기로 처리
        if (input == -1) {
            goBack();
        }
        // 그 외의 입력은 현재 뷰에서 처리
    }
}

void screenController::navigateTo(const std::string& viewId) {
    auto newView = createView(viewId);
    if (newView) {
        viewStack.push(newView);
        newView->display();  // 새로운 화면 표시
    }
}

void screenController::goBack() {
    if (canGoBack()) {
        viewStack.pop();
        if (!viewStack.empty()) {
            viewStack.top()->display();  // 이전 화면 다시 표시
        }
    }
}

bool screenController::canGoBack() const {
    return viewStack.size() > 1;  // 최소 1개의 화면은 남겨둠
}

void screenController::clearStackAndNavigateTo(const std::string& viewId) {
    while (!viewStack.empty()) {
        viewStack.pop();
    }
    navigateTo(viewId);
}

// 화면 생성
std::shared_ptr<baseScreenView> screenController::createView(const std::string& viewId) {
    if (viewId == "test1") {
        return std::make_shared<TestView1>();
    } else if (viewId == "test2") {
        return std::make_shared<TestView2>();
    } else if (viewId == "test3") {
        return std::make_shared<TestView3>();
    }
    return nullptr;
} 