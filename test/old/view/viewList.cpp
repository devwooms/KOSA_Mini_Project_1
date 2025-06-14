#include "viewList.h"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

using namespace std;

ViewList::ViewList(const string& title, ViewList* parent) 
    : title(title), isVisible(false), selectedIndex(0), parentMenu(parent) {
    menuPath();
}

// 모두 지우기
void ViewList::clearScreen() const {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// 현재 메뉴 경로 표시
void ViewList::menuPath() {
    thisPath = title;
    ViewList* current = parentMenu;
    while (current != nullptr) {
        thisPath = current->title + " > " + thisPath;
        current = current->parentMenu;
    }
}

// 테두리 그리기
void ViewList::drawBorder(const string& text) const {
    string line(text.length() + 4, '-');
    cout << "\033[38;5;147m"; // 파란색 시작
    cout << "┌" << line << "┐" << endl;
    cout << "│  " << text << "  │" << endl;
    cout << "└" << line << "┘" << endl;
    cout << "\033[0m"; // 색상 리셋
    
    // 경로 표시
    cout << "\033[90m" << thisPath << "\033[0m" << endl << endl;
}

// 메뉴 아이템 추가
void ViewList::addMenuItem(const string& text, function<void()> action, 
                         bool isEnabled, const string& shortcut) {
    menuItems.push_back(MenuItem(text, action, isEnabled, shortcut));
}

// 서브메뉴 추가
void ViewList::addSubMenu(const string& text, shared_ptr<ViewList> subMenu,
                         bool isEnabled, const string& shortcut) {
    MenuItem item(text, nullptr, isEnabled, shortcut);
    item.subMenu = subMenu;
    menuItems.push_back(item);
}

// 메뉴 아이템 삭제
void ViewList::removeMenuItem(int index) {
    if (index >= 0 && index < menuItems.size()) {
        menuItems.erase(menuItems.begin() + index);
        if (selectedIndex >= menuItems.size()) {
            selectedIndex = menuItems.size() - 1;
        }
    }
}

// 메뉴 아이템 업데이트
void ViewList::updateMenuItem(int index, const string& text, function<void()> action) {
    if (index >= 0 && index < menuItems.size()) {
        menuItems[index].text = text;
        if (action) {
            menuItems[index].action = action;
        }
    }
}

// 메뉴 아이템 활성화/비활성화
void ViewList::enableMenuItem(int index, bool enable) {
    if (index >= 0 && index < menuItems.size()) {
        menuItems[index].isEnabled = enable;
    }
}

// 메뉴 표시
void ViewList::show() {
    isVisible = true;
    refresh();
}

// 메뉴 숨기기
void ViewList::hide() {
    isVisible = false;
    clearScreen();
}

// 메뉴 새로고침
void ViewList::refresh() {
    if (!isVisible) return;
    
    clearScreen();
    drawBorder(title);
    
    for (size_t i = 0; i < menuItems.size(); ++i) {
        const auto& item = menuItems[i];
        
        // 선택된 항목 하이라이트
        if (i == selectedIndex) {
            cout << "\033[1;34m"; // 파란색 굵게
        }
        
        // 비활성화된 항목 회색으로
        if (!item.isEnabled) {
            cout << "\033[2m"; // 흐리게
        }
        
        // 메뉴 항목 출력
        cout << i + 1 << ". " << item.text;
        
        // 서브메뉴 표시
        if (item.subMenu) {
            cout << " >";
        }
        
        // 단축키가 있으면 출력
        if (!item.shortcut.empty()) {
            cout << " (" << item.shortcut << ")";
        }
        
        cout << "\033[0m" << endl; // 스타일 리셋
    }
    
    // 뒤로가기 메뉴 추가 (루트 메뉴가 아닌 경우)
    if (parentMenu) {
        cout << "0. 뒤로 가기" << endl;
    }
    cout << endl;
}

// 부모 메뉴로 돌아가기
void ViewList::goBack() {
    if (parentMenu) {
        hide();
        parentMenu->show();
    }
}

// 메뉴 실행
void ViewList::run() {
    show();
    
    while (isVisible) {
        cout << "선택 (";
        if (parentMenu) cout << "0-";
        cout << menuItems.size() << "): ";
        
        int choice;
        cin >> choice;
        
        if (parentMenu && choice == 0) {
            goBack();
            return;
        }
        
        if (choice < 1 || choice > menuItems.size()) {
            cout << "잘못된 선택입니다." << endl;
            continue;
        }
        
        int index = choice - 1;
        if (!menuItems[index].isEnabled) {
            cout << "이 메뉴는 현재 사용할 수 없습니다." << endl;
            continue;
        }
        
        selectedIndex = index;
        
        // 서브메뉴가 있는 경우
        if (menuItems[index].subMenu) {
            menuItems[index].subMenu->run();
            refresh();  // 서브메뉴에서 돌아왔을 때 화면 갱신
        }
        // 액션이 있는 경우
        else if (menuItems[index].action) {
            menuItems[index].action();
            refresh();  // 액션 실행 후 화면 갱신
        }
    }
}

// 메뉴 제목 설정
void ViewList::setTitle(const string& newTitle) {
    title = newTitle;
    menuPath();
    if (isVisible) {
        refresh();
    }
}

// 선택된 메뉴 인덱스 설정
void ViewList::setSelectedIndex(int index) {
    if (index >= 0 && index < menuItems.size()) {
        selectedIndex = index;
        if (isVisible) {
            refresh();
        }
    }
}
