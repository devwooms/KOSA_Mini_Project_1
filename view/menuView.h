#ifndef MENU_VIEW_H
#define MENU_VIEW_H

#include <string>
#include <vector>
#include <functional>

// 메뉴 아이템 구조체
struct MenuItem {
    std::string id;                     // 메뉴 ID (예: "1", "1.1", "1.2.1")
    std::string name;                   // 메뉴 이름
    std::function<void()> action;       // 메뉴 실행시 동작
    int depth;                          // 메뉴 트리 구조 깊이
};

// 메뉴 관리 클래스
class MenuView {
public:
    MenuView();
    void run();

private:
    std::vector<MenuItem> menus;     // 모든 메뉴 항목
    std::string currentMenuId;       // 현재 메뉴 ID

    void displayMenu() const;        // 현재 수준의 메뉴 표시
    int getChoice() const;           // 사용자 입력 받기
    bool userChoice(int choice);   // 선택 처리
    
    // 현재 메뉴의 상위 메뉴 ID 가져오기
    std::string getParentId() const;
    // 현재 메뉴 수준의 항목들 가져오기
    std::vector<MenuItem> getCurrentLevelMenus() const;

    // 메뉴 동작 함수들
    void searchProduct() const;      // 제품 검색
    void viewProducts() const;       // 제품 조회
    void addProduct() const;         // 제품 입력
    void updateProduct() const;      // 제품 수정
    void deleteProduct() const;      // 제품 삭제
    void viewInventory() const;      // 재고 조회
    void addInventory() const;       // 재고 입력
    void updateInventory() const;    // 재고 증가/차감
    void signUp() const;             // 회원가입
};

#endif 