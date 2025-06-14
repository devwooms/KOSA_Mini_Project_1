#ifndef VIEW_LIST_H
#define VIEW_LIST_H

#include <string>
#include <vector>
#include <functional>
#include <memory>

using namespace std;

class ViewList;

// 메뉴 아이템 구조체
struct MenuItem {
    string text;                     // 메뉴 텍스트
    function<void()> action;         // 메뉴 선택시 실행될 함수
    bool isEnabled;                  // 메뉴 활성화 여부
    string shortcut;                 // 단축키 (선택사항)
    shared_ptr<ViewList> subMenu;    // 서브메뉴 (nullptr이면 leaf 노드)
    
    MenuItem(const string& text, function<void()> action = nullptr, bool isEnabled = true, const string& shortcut = "")
        : text(text), action(action), isEnabled(isEnabled), shortcut(shortcut), subMenu(nullptr) {}
};

class ViewList {
private:
    vector<MenuItem> menuItems;      // 메뉴 아이템 목록
    string title;                    // 메뉴 제목
    bool isVisible;                  // 메뉴 표시 여부
    int selectedIndex;              // 현재 선택된 메뉴 인덱스
    ViewList* parentMenu;           // 부모 메뉴에 대한 포인터
    string thisPath;              // 현재 메뉴 경로
    
    // 내부 유틸리티 함수
    void drawBorder(const string& text) const;
    void clearScreen() const;
    // 메뉴 경로 표시
    void menuPath();

public:
    ViewList(const string& title = "Menu", ViewList* parent = nullptr);
    
    // 메뉴 관리 함수
    void addMenuItem(const string& text, function<void()> action = nullptr, 
                    bool isEnabled = true, const string& shortcut = "");
    void addSubMenu(const string& text, shared_ptr<ViewList> subMenu, 
                   bool isEnabled = true, const string& shortcut = "");
    void removeMenuItem(int index);
    void updateMenuItem(int index, const string& text, function<void()> action = nullptr);
    void enableMenuItem(int index, bool enable = true);
    
    // 메뉴 표시 및 실행 함수
    void show();
    void hide();
    void refresh();
    void run();
    void goBack();  // 부모 메뉴로 돌아가기
    
    // 스타일링 함수
    void setTitle(const string& newTitle);
    void setSelectedIndex(int index);
    
    // 게터 함수
    bool isMenuVisible() const { return isVisible; }
    int getSelectedIndex() const { return selectedIndex; }
    int getMenuItemCount() const { return menuItems.size(); }
    ViewList* getParentMenu() const { return parentMenu; }
    string getThisPath() const { return thisPath; }
};

#endif
