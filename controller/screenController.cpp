#include "screenController.h"
#include "../view/baseScreenView.h"
#include "../view/screens/homeView.h"
#include "../view/screens/loginView.h"
#include "../view/screens/signupView.h"
#include "../view/screens/consumerView.h"
#include "../view/screens/adminView.h"
#include <iostream>
#include <limits>
#include <thread>
#include <chrono>

screenController::screenController() {
    // 화면들 등록
    registerScreen("home", std::make_shared<homeView>());
    registerScreen("login", std::make_shared<loginView>());
    registerScreen("signup", std::make_shared<signupView>());
    registerScreen("consumer", std::make_shared<consumerView>());
    registerScreen("admin", std::make_shared<adminView>());
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
    // 초기 화면으로 home을 설정
    navigateTo("home");

    bool running = true;
    while (running && !screenStack.empty()) {
        auto currentScreen = screenStack.top();
        
        // 현재 화면 표시
        currentScreen->display();
        
        // 회원가입 화면인 경우 특별 처리
        if (auto signupScreen = dynamic_cast<signupView*>(currentScreen.get())) {
            std::string input;
            std::getline(std::cin, input);
            
            if (input == "0") {  // 뒤로가기
                goBack();
                continue;
            }
            
            signupScreen->processInput(input);
            if (signupScreen->validateInput()) {
                // 회원가입 완료 처리
                std::cout << "\n회원가입이 완료되었습니다!\n";
                std::this_thread::sleep_for(std::chrono::seconds(1));
                goBack();
            } else if (signupScreen->isPasswordMismatch()) {
                std::cout << "\n비밀번호가 일치하지 않습니다!\n";
                std::this_thread::sleep_for(std::chrono::seconds(1));
                goBack();
            }
            continue;
        }
        
        // 일반 메뉴 화면 처리
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
        screen->resetState();  // 화면 전환 시 상태 초기화
        screenStack.push(screen);
    }
}

void screenController::goBack() {
    if (!screenStack.empty()) {
        screenStack.top()->resetState();  // 현재 화면의 상태 초기화
        screenStack.pop();
    }
}

void screenController::registerScreen(const std::string& name, std::shared_ptr<baseScreenView> screen) {
    screens[name] = screen;
    screen->setController(this);
} 