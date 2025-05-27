#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

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
    clearScreen();
    mainTiTle();
    std::cout << "=== 메인 메뉴 ===" << std::endl;
    std::cout << "1. 첫 번째 메뉴" << std::endl;
    std::cout << "2. 두 번째 메뉴" << std::endl;
    std::cout << "3. 세 번째 메뉴" << std::endl;
    std::cout << "4. 네 번째 메뉴" << std::endl;
    std::cout << "5. 다섯 번째 메뉴" << std::endl;
    std::cout << "0. 종료" << std::endl;
    std::cout << "선택: ";
}

void displaySubMenu(int mainChoice) {
    clearScreen();
    std::cout << "=== " << mainChoice << "번 메뉴의 하위 메뉴 ===" << std::endl;
    for(int i = 1; i <= 5; i++) {
        std::cout << mainChoice << "-" << i << ". " << mainChoice << "번의 " << i << "번째 하위 메뉴" << std::endl;
    }
    std::cout << "0. 이전 메뉴로" << std::endl;
    std::cout << "선택: ";
}

void displaySubSubMenu(int mainChoice, int subChoice) {
    clearScreen();
    std::cout << "=== " << mainChoice << "-" << subChoice << "번 메뉴의 하위 메뉴 ===" << std::endl;
    for(int i = 1; i <= 5; i++) {
        std::cout << mainChoice << "-" << subChoice << "-" << i << ". " 
                  << mainChoice << "-" << subChoice << "번의 " << i << "번째 하위 메뉴" << std::endl;
    }
    std::cout << "0. 이전 메뉴로" << std::endl;
    std::cout << "선택: ";
}

void displaySelectedMenu(int mainChoice, int subChoice, int subSubChoice) {
    clearScreen();
    std::cout << "선택하신 메뉴: " << mainChoice << "-" << subChoice << "-" << subSubChoice << std::endl;
    std::cout << "이 메뉴의 기능이 실행됩니다." << std::endl;
    std::cout << "\n계속하려면 아무 키나 누르세요...";
    std::cin.ignore();
    std::cin.get();
}

int main() {
    int mainChoice, subChoice, subSubChoice;

    while(true) {
        displayMainMenu();
        std::cin >> mainChoice;

        if(mainChoice == 0) {
            clearScreen();
            std::cout << "프로그램을 종료합니다." << std::endl;
            break;
        }

        if(mainChoice >= 1 && mainChoice <= 5) {
            while(true) {
                displaySubMenu(mainChoice);
                std::cin >> subChoice;

                if(subChoice == 0) break;

                if(subChoice >= 1 && subChoice <= 5) {
                    while(true) {
                        displaySubSubMenu(mainChoice, subChoice);
                        std::cin >> subSubChoice;

                        if(subSubChoice == 0) break;

                        if(subSubChoice >= 1 && subSubChoice <= 5) {
                            displaySelectedMenu(mainChoice, subChoice, subSubChoice);
                        } else {
                            clearScreen();
                            std::cout << "잘못된 선택입니다." << std::endl;
                            std::cout << "\n계속하려면 아무 키나 누르세요...";
                            std::cin.ignore();
                            std::cin.get();
                        }
                    }
                } else {
                    clearScreen();
                    std::cout << "잘못된 선택입니다." << std::endl;
                    std::cout << "\n계속하려면 아무 키나 누르세요...";
                    std::cin.ignore();
                    std::cin.get();
                }
            }
        } else {
            clearScreen();
            std::cout << "잘못된 선택입니다." << std::endl;
            std::cout << "\n계속하려면 아무 키나 누르세요...";
            std::cin.ignore();
            std::cin.get();
        }
    }
    
    return 0;
} 