#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

#include "customer/customerMenu.h"
#include "admin/adminMenu.h"

void mainTiTle(){
    std::string title = "KOSA 편의점";
    std::string line(title.size() + 4, '-');
    std::cout << "\033[1;34m"; // 파란색 시작
    std::cout << "┌" << line << "┐" << std::endl;
    std::cout << "│    " << title << "   │" << std::endl;
    std::cout << "└" << line << "┘" << std::endl;
    std::cout << "\033[0m"; // 색상 리셋   
}

// 화면 지우기
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void displayMainMenu() {
    int mainChoice;
    clearScreen();
    mainTiTle();
    std::cout << "=== 메인 메뉴 ===" << std::endl;
    std::cout << "1. 소비자" << std::endl;
    std::cout << "2. 관리자" << std::endl;
    std::cout << "0. 종료" << std::endl;
    std::cout << "선택: ";
    std::cin >> mainChoice;

    switch(mainChoice){
        case 1:
            customerMenu();
            break;
        case 2:
            adminMenu();
            break;
        case 0:
            return;
        default:
            std::cout << "잘못된 선택입니다." << std::endl;
            break;
    }
}

int main(){
    displayMainMenu();
    return 0;
}