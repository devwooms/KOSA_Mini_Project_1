#include "MenuViewSettings.hpp"
#include "MenuViewRenderer.hpp"
#include <iostream>

// 메뉴 동작 함수들
void loginAction() {
    std::cout << "\n로그인 처리 중...\n";
    std::cout << "아무 키나 누르면 돌아갑니다...";
    std::cin.ignore();
    std::cin.get();
}

void signUpAction() {
    std::cout << "\n회원가입 처리 중...\n";
    std::cout << "아무 키나 누르면 돌아갑니다...";
    std::cin.ignore();
    std::cin.get();
}

// 사용 예제
void exampleUsage() {
    // 메뉴 설정 생성
    MenuViewSettings settings;
    
    // 타이틀 설정
    settings.setTitle("메인 메뉴");
    
    // 메뉴 항목 추가 (각각의 액션과 함께)
    settings.addMenuItem("로그인", 1, loginAction);
    settings.addMenuItem("회원가입", 2, signUpAction);
    settings.addMenuItem("종료", 0);
    
    // 에러 메시지 추가 (필요한 경우)
    settings.addErrorMessage("잘못된 선택입니다.");
    
    // 입력 프롬프트 설정
    settings.setInputPrompt("원하시는 메뉴를 선택하세요: ");
    
    bool running = true;
    while (running) {
        // 메뉴 렌더링
        MenuViewRenderer::renderFullMenu(settings);
        
        // 사용자 입력 처리
        int choice;
        std::cin >> choice;
        
        // 종료 처리
        if (choice == 0) {
            running = false;
            continue;
        }
        
        // 메뉴 액션 실행
        if (!settings.handleChoice(choice - 1)) {  // 메뉴 인덱스는 0부터 시작하므로 -1
            settings.clearErrorMessages();
            settings.addErrorMessage("잘못된 선택입니다.");
        }
    }
} 