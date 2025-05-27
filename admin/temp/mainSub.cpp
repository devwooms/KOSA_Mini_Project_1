#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

using namespace std;


void mainTiTle(){
    string title = "KOSA 편의점";
    string line(title.size() + 4, '-');
    cout << "\033[1;34m"; // 파란색 시작
    cout << "┌" << line << "┐" << endl;
    cout << "│    " << title << "   │" << endl;
    cout << "└" << line << "┘" << endl;
    cout << "\033[0m"; // 색상 리셋   
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
    cout << "=== 메인 메뉴 ===" << endl;
    cout << "1. 첫 번째 메뉴" << endl;
    cout << "2. 두 번째 메뉴" << endl;
    cout << "3. 관리자 메뉴" << endl;
    cout << "4. 네 번째 메뉴" << endl;
    cout << "5. 다섯 번째 메뉴" << endl;
    cout << "0. 종료" << endl;
    cout << "선택: ";
}

void displaySubMenu(int mainChoice) {
    clearScreen();
    cout << "=== " << mainChoice << "번 메뉴의 하위 메뉴 ===" << endl;
    for(int i = 1; i <= 5; i++) {
        cout << mainChoice << "-" << i << ". " << mainChoice << "번의 " << i << "번째 하위 메뉴" << endl;
    }
    cout << "0. 이전 메뉴로" << endl;
    cout << "선택: ";
}

void displaySubSubMenu(int mainChoice, int subChoice) {
    clearScreen();
    cout << "=== " << mainChoice << "-" << subChoice << "번 메뉴의 하위 메뉴 ===" << endl;
    for(int i = 1; i <= 5; i++) {
        cout << mainChoice << "-" << subChoice << "-" << i << ". " 
                  << mainChoice << "-" << subChoice << "번의 " << i << "번째 하위 메뉴" << endl;
    }
    cout << "0. 이전 메뉴로" << endl;
    cout << "선택: ";
}

void displaySelectedMenu(int mainChoice, int subChoice, int subSubChoice) {
    clearScreen();
    cout << "선택하신 메뉴: " << mainChoice << "-" << subChoice << "-" << subSubChoice << endl;
    cout << "이 메뉴의 기능이 실행됩니다." << endl;
    cout << "\n계속하려면 아무 키나 누르세요...";
    cin.ignore();
    cin.get();
}

void adminMenu(){
    int adminChoice;
    clearScreen();
    mainTiTle();
    cout << "=== 관리자 메뉴 ===" << endl;
    cout << "1. 제품 관리" << endl;
    cout << "0. 뒤로 가기" << endl;
    cout << "선택: ";
    cin >> adminChoice;

    if(adminChoice == 0){
        return;
    } else if(adminChoice == 1){
        clearScreen();
        cout << "=== 제품 관리 메뉴 ===" << endl;
        cout << "1. 제품 입력" << endl;
        cout << "2. 제품 수정" << endl;
        cout << "3. 제품 삭제" << endl;
        cout << "4. 제품 조회" << endl;
        cout << "0. 뒤로 가기" << endl;
        cout << "선택: ";
        cin >> adminChoice;

        switch(adminChoice){
            case 1:
                {
                    cout << "제품 입력 기능이 실행됩니다." << endl;
                    string name, category, brand;
                    int price;
                    
                    cout << "제품 이름: ";
                    cin >> name;
                    cout << "제품 카테고리: ";
                    cin >> category;
                    cout << "제품 가격: ";
                    cin >> price;
                    cout << "제품 브랜드: ";
                    cin >> brand;

                    Product newProduct(name, category, price, brand);
                    newProduct.displayInfo();
                    
                    
                }
                break;
            case 2:
                cout << "제품 수정 기능이 실행됩니다." << endl;
                break;
            case 3:
                cout << "제품 삭제 기능이 실행됩니다." << endl;
                break;
            case 0:
                return;
            default:
                cout << "잘못된 선택입니다." << endl;
                break;
        }
    }

}

int main() {
    int mainChoice, subChoice, subSubChoice;

    while(true) {
        displayMainMenu();
        cin >> mainChoice;

        if(mainChoice == 0) {
            clearScreen();
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        if(mainChoice == 1 || mainChoice == 2 || mainChoice == 4 || mainChoice == 5) {
            while(true) {
                displaySubMenu(mainChoice);
                cin >> subChoice;

                if(subChoice == 0) {
                    break;
                }
                if(subChoice >= 1 && subChoice <= 5) {
                    while(true) {
                        displaySubSubMenu(mainChoice, subChoice);
                        cin >> subSubChoice;

                        if(subSubChoice == 0) {
                            break;
                        }

                        if(subSubChoice >= 1 && subSubChoice <= 5) {
                            displaySelectedMenu(mainChoice, subChoice, subSubChoice);
                        } else {
                            clearScreen();
                            cout << "잘못된 선택입니다." << endl;
                            cout << "\n계속하려면 아무 키나 누르세요...";
                            cin.ignore();
                            cin.get();
                        }
                    }
                } else {
                    clearScreen();
                    cout << "잘못된 선택입니다." << endl;
                    cout << "\n계속하려면 아무 키나 누르세요...";
                    cin.ignore();
                    cin.get();
                }
            }
        } else if(mainChoice == 3) {
            int adminChoice;
            while(true) {
                adminMenu();
                cin >> adminChoice;
                
                if(adminChoice == 2) {
                    break;
                } else if(adminChoice == 1) {
                    clearScreen();
                    cout << "제품 관리 기능이 실행됩니다." << endl;
                    cout << "\n계속하려면 아무 키나 누르세요...";
                    cin.ignore();
                    cin.get();
                } else {
                    clearScreen();
                    cout << "잘못된 선택입니다." << endl;
                    cout << "\n계속하려면 아무 키나 누르세요...";
                    cin.ignore();
                    cin.get();
                }
            }
        } else {
            clearScreen();
            cout << "잘못된 선택입니다." << endl;
            cout << "\n계속하려면 아무 키나 누르세요...";
            cin.ignore();
            cin.get();
        }
    }
    
    return 0;
} 