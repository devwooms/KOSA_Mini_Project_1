#include "screenController.h"
#include <iostream>
#include <memory>

screenController::screenController() {
    // 뷰 레지스트리 초기화
    viewRegistry["test1"] = std::make_shared<TestView1>();
    viewRegistry["test2"] = std::make_shared<TestView2>();
    viewRegistry["test3"] = std::make_shared<TestView3>();
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
        transitionTo(newView);
        viewStack.push(newView);
    }
}

void screenController::goBack() {
    if (canGoBack()) {
        viewStack.pop();
        if (!viewStack.empty()) {
            auto previousView = viewStack.top();
            transitionTo(previousView);
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

void screenController::transitionTo(std::shared_ptr<baseScreenView> view) {
    if (view) {
        view->clearScreen();
        view->clearErrors();
    }
}

std::shared_ptr<baseScreenView> screenController::createView(const std::string& viewId) {
    auto it = viewRegistry.find(viewId);
    if (it != viewRegistry.end()) {
        // 뷰의 새로운 인스턴스 생성
        return std::make_shared<std::remove_reference_t<decltype(*it->second)>>(*it->second);
    }
    return nullptr;
} 