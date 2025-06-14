#include "menuView.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include "../util.hpp"

using namespace std;
using namespace Util;

// 메뉴 동작 함수들의 구현
void MenuView::searchProduct() const {
    clearScreen();
    cout << "\n=== 제품 검색 ===\n";
    cout << "검색어를 입력하세요: ";
    string searchTerm;
    getline(cin, searchTerm);
    cout << "제품 검색 중...\n";
}

void MenuView::viewProducts() const {
    clearScreen();
    cout << "\n=== 제품 목록 ===\n";
    cout << "제품 목록을 표시합니다...\n";
}

void MenuView::addProduct() const {
    clearScreen();
    cout << "\n=== 새로운 제품 입력 ===\n";
    cout << "제품 정보를 입력하세요...\n";
}

void MenuView::updateProduct() const {
    clearScreen();
    cout << "\n=== 제품 정보 수정 ===\n";
    cout << "수정할 제품 ID를 입력하세요: ";
    string productId;
    getline(cin, productId);
}

void MenuView::deleteProduct() const {
    clearScreen();
    cout << "\n=== 제품 삭제 ===\n";
    cout << "삭제할 제품 ID를 입력하세요: ";
    string productId;
    getline(cin, productId);
}

void MenuView::viewInventory() const {
    clearScreen();
    cout << "\n=== 재고 현황 ===\n";
    cout << "현재 재고 현황을 표시합니다...\n";
}

void MenuView::addInventory() const {
    clearScreen();
    cout << "\n=== 새로운 재고 입력 ===\n";
    cout << "제품 ID: ";
    string productId;
    getline(cin, productId);
    cout << "수량: ";
    string quantity;
    getline(cin, quantity);
}

void MenuView::updateInventory() const {
    clearScreen();
    cout << "\n=== 재고 수량 수정 ===\n";
    cout << "제품 ID: ";
    string productId;
    getline(cin, productId);
    cout << "증가/차감 수량(+/-): ";
    string quantity;
    getline(cin, quantity);
}

void MenuView::signUp() const {
    clearScreen();
    cout << "\n=== 회원가입 ===\n";
    cout << "아이디: ";
    string id;
    getline(cin, id);
    cout << "비밀번호: ";
    string password;
    getline(cin, password);
    cout << "비밀번호 확인: ";
    string confirmPassword;
    getline(cin, confirmPassword);
    cout << "\n회원가입 처리 중...\n";
}

// 메인메뉴 타이틀
MenuView::MenuView() {
    menus = {
        // 메인 메뉴
        {"1", "로그인", nullptr, 0},
        {"2", "회원가입", nullptr, 0},
        
        // 1. 로그인 하위 메뉴
        {"1.1", "소비자", nullptr, 1},
        {"1.2", "관리자", nullptr, 1},
        
        // 1.1 소비자 하위 메뉴
        {"1.1.1", "제품 검색", [this]() { searchProduct(); }, 2},
        
        // 1.2 관리자 하위 메뉴
        {"1.2.1", "제품 관리", nullptr, 2},
        {"1.2.2", "재고 관리", nullptr, 2},
        
        // 1.2.1 제품 관리 하위 메뉴
        {"1.2.1.1", "제품 조회", [this]() { viewProducts(); }, 3},
        {"1.2.1.2", "제품 입력", [this]() { addProduct(); }, 3},
        {"1.2.1.3", "제품 수정", [this]() { updateProduct(); }, 3},
        {"1.2.1.4", "제품 삭제", [this]() { deleteProduct(); }, 3},
        
        // 1.2.2 재고 관리 하위 메뉴
        {"1.2.2.1", "재고 조회", [this]() { viewInventory(); }, 3},
        {"1.2.2.2", "재고 입력", [this]() { addInventory(); }, 3},
        {"1.2.2.3", "재고 증가/차감", [this]() { updateInventory(); }, 3},
        
        // 2. 회원가입 하위 메뉴
        {"2.1", "회원가입 기능", [this]() { signUp(); }, 1}
    };
    
    currentMenuId = "";  // 루트 메뉴
}

// 현재 메뉴의 상위 메뉴 ID 가져오기
string MenuView::getParentId() const {
    size_t lastDot = currentMenuId.find_last_of('.');
    if (lastDot == string::npos) {
        return "";
    }
    return currentMenuId.substr(0, lastDot);
}

// 현재 메뉴 수준의 항목들 가져오기
vector<MenuItem> MenuView::getCurrentLevelMenus() const {
    vector<MenuItem> currentMenus;
    string prefix = currentMenuId.empty() ? "" : currentMenuId + ".";
    int targetDepth = currentMenuId.empty() ? 0 : count(currentMenuId.begin(), currentMenuId.end(), '.') + 1;
    
    for (const auto& menu : menus) {
        if (currentMenuId.empty() && menu.depth == 0) {
            currentMenus.push_back(menu);
        }
        else if (!currentMenuId.empty() && 
                 menu.id.find(prefix) == 0 && 
                 menu.id.find('.', prefix.length()) == string::npos) {
            currentMenus.push_back(menu);
        }
    }
    
    return currentMenus;
}

// 현재 메뉴 표시
void MenuView::displayMenu() const {
    clearScreen();
    auto currentMenus = getCurrentLevelMenus();
    string menuTitle = currentMenuId.empty() ? "메인 메뉴" : 
        find_if(menus.begin(), menus.end(), 
            [this](const MenuItem& m) { return m.id == currentMenuId; })->name;
            
    cout << "\n=== " << menuTitle << " ===\n\n";
    
    int index = 1;
    for (const auto& menu : currentMenus) {
        cout << index++ << ". " << menu.name;
        // 하위 메뉴가 있는지 확인
        bool hasSubMenu = any_of(menus.begin(), menus.end(),
            [&menu](const MenuItem& m) { 
                return m.id.find(menu.id + ".") == 0; 
            });
        cout << "\n";
    }
    
    cout << "0. " << (currentMenuId.empty() ? "종료" : "이전 메뉴로 돌아가기") << "\n\n";
}

// 메뉴 선택 받기
int MenuView::getChoice() const {
    int choice;
    cout << "메뉴를 선택하세요: ";
    cin >> choice;
    clearBuffer();
    return choice;
}

// 메뉴 선택 처리
bool MenuView::userChoice(int choice) {
    auto currentMenus = getCurrentLevelMenus();
    
    if (choice == 0) {
        // 메인 메뉴에서 0을 고르면 프로그램 종료
        if (currentMenuId.empty()) {
            cout << "\n프로그램을 종료합니다.\n";
            return false;
        }
        // 이전 메뉴로 돌아가기
        currentMenuId = getParentId();
        return true;
    }
    
    // 메뉴 선택 처리
    if (choice > 0 && choice <= static_cast<int>(currentMenus.size())) {
        const auto& selectedMenu = currentMenus[choice - 1];
        
        // 메뉴 동작 함수 호출
        if (selectedMenu.action) {
            selectedMenu.action();
        } else {
            // 하위 메뉴로 이동
            currentMenuId = selectedMenu.id;
        }
        return true;
    }
    
    cout << "\n잘못된 선택입니다. 다시 시도해주세요.\n";
    return true;
}

// 메뉴 실행
void MenuView::run() {
    while (true) {
        displayMenu();
        int choice = getChoice();
        if (!userChoice(choice)) {
            clearScreen();  // 프로그램 종료 시 화면 지우기
            break;
        }
    }
} 