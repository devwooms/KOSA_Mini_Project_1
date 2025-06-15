#include "screenController.h"
#include "../view/baseScreenView.h"
#include "../view/screens/TestView1.h"
#include "../view/screens/TestView2.h"
#include "../view/screens/TestView3.h"
#include <iostream>
#include <limits>

screenController::screenController() {
    // 테스트 화면들 등록
    registerScreen("test1", std::make_shared<TestView1>());
    registerScreen("test2", std::make_shared<TestView2>());
    registerScreen("test3", std::make_shared<TestView3>());
}

int screenController::getInput(int maxChoice) {
    int choice;
    while (true) {
        if (screenStack.size() > 1) {
            std::cout << "선택하세요 (0: 뒤로가기, 1-" << maxChoice << "): ";
        } else {
            std::cout << "선택하세요 (0: 종료, 1-" << maxChoice << "): ";
        }
        
        if (std::cin >> choice) {
            // 입력 버퍼 비우기
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            // 유효한 입력인지 확인
            if (choice >= 0 && choice <= maxChoice) {
                return choice;
            }
        } else {
            // 잘못된 입력 처리
            std::cin.clear();  // 오류 상태 초기화
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "잘못된 입력입니다. 다시 선택하세요.\n";
    }
}

void screenController::run() {
    // 초기 화면으로 test1을 설정
    navigateTo("test1");

    bool running = true;
    while (running && !screenStack.empty()) {
        auto currentScreen = screenStack.top();
        
        // 현재 화면 표시
        currentScreen->display();
        
        // 사용자 입력 처리
        int maxChoice = currentScreen->getMenuItems().size();
        int choice = getInput(maxChoice);
        
        if (choice == 0) {
            if (screenStack.size() > 1) {
                goBack();
            } else {
                // 메인 화면에서 0을 선택하면 프로그램 종료
                running = false;
            }
        } else if (choice > 0 && choice <= maxChoice) {
            // 메뉴 액션 실행 (choice는 1부터 시작하므로 인덱스로 변환)
            const auto& actions = currentScreen->getMenuActions();
            if (choice <= actions.size()) {
                actions[choice - 1]();
            }
        }
    }
    
    std::cout << "\n프로그램을 종료합니다.\n";
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