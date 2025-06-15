#include "HomeView.h"
#include "../../controller/ScreenController.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include "LoginView.h"
#include "SignupView.h"

HomeView::HomeView() {
    setErrorMessages({"잘못된 입력입니다. 다시 선택하세요."});
    setTitle("KOSA 편의점");
    setMenuItems({
        "로그인",
        "회원가입",
    });
    setMenuActions({
        [this]() { 
            // 로그인 화면으로 이동
            auto loginScreen = std::make_shared<LoginView>();
            getController()->pushScreen(loginScreen);
        },
        [this]() { 
            // 회원가입 화면으로 이동
            auto signupScreen = std::make_shared<SignupView>();
            getController()->pushScreen(signupScreen);
        }
    });
}

int HomeView::getUserChoice() {
    int choice;
    while (true) {
        std::cout << "선택하세요 (0: 종료, 1~" << getMenuItems().size() << "): ";
        
        if (std::cin >> choice) {
            // 입력 버퍼 비우기
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            // 유효한 입력인지 확인
            if (choice >= 0 && choice <= static_cast<int>(getMenuItems().size())) {
                return choice;
            }
        } else {
            // 잘못된 입력 처리
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << getErrorMessages()[0] << std::endl;
    }
    return choice;
}

void HomeView::run() {
    // 화면 지우기
    clearScreen();
    
    // 타이틀 표시 (ViewUtil 활용)
    renderTitle(getTitle());
    
    // 메뉴 표시 (ViewUtil 활용)
    renderMenuItems(getMenuItems());
    
    // 사용자 입력 받기
    int choice = getUserChoice();
    
    // 선택 처리
    if (choice == 0) {
        // 종료 - 스택에서 제거하여 프로그램 종료
        getController()->popScreen();
    } else if (choice > 0 && choice <= static_cast<int>(getMenuItems().size())) {
        // 생성자에서 설정한 menuActions 활용
        const auto& actions = getMenuActions();
        if (choice <= actions.size() && actions[choice - 1]) {
            actions[choice - 1]();  // 설정된 액션 실행
        }
    }
}

