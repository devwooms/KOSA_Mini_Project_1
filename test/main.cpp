#include <iostream>
#include <memory>
#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif
#include "view/viewSetting.h"

using namespace std;

int main() {
    // 메인 메뉴 생성
    auto mainMenu = make_shared<ViewSetting>("KOSA 편의점");
    
    // 소비자 메뉴 생성
    auto customerMenu = make_shared<ViewSetting>("소비자 메뉴", mainMenu.get());
    customerMenu->addMenuItem("제품 목록 보기", []() {
        cout << "\n현재 준비 중인 기능입니다." << endl;
        cout << "아무 키나 눌러주세요..." << endl;
        cin.ignore();
        cin.get();
    });
    
    // 관리자 메뉴 생성
    auto adminMenu = make_shared<ViewSetting>("관리자 메뉴", mainMenu.get());
    
    // 제품 관리 메뉴 생성
    auto productMenu = make_shared<ViewSetting>("제품 관리", adminMenu.get());
    productMenu->addMenuItem("제품 조회", []() {
        cout << "\n제품 목록을 조회합니다..." << endl;
        cout << "아무 키나 눌러주세요..." << endl;
        cin.ignore();
        cin.get();
    });
    
    productMenu->addMenuItem("제품 입력", []() {
        cout << "\n새로운 제품을 입력합니다..." << endl;
        cout << "아무 키나 눌러주세요..." << endl;
        cin.ignore();
        cin.get();
    });
    
    productMenu->addMenuItem("제품 수정", []() {
        cout << "\n제품 정보를 수정합니다..." << endl;
        cout << "아무 키나 눌러주세요..." << endl;
        cin.ignore();
        cin.get();
    });
    
    productMenu->addMenuItem("제품 삭제", []() {
        cout << "\n제품을 삭제합니다..." << endl;
        cout << "아무 키나 눌러주세요..." << endl;
        cin.ignore();
        cin.get();
    });
    
    // 재고 관리 메뉴 생성
    auto stockMenu = make_shared<ViewSetting>("재고 관리", adminMenu.get());
    stockMenu->addMenuItem("재고 조회", []() {
        cout << "\n재고 현황을 조회합니다..." << endl;
        cout << "아무 키나 눌러주세요..." << endl;
        cin.ignore();
        cin.get();
    });
    
    stockMenu->addMenuItem("재고 입력", []() {
        cout << "\n새로운 재고를 입력합니다..." << endl;
        cout << "아무 키나 눌러주세요..." << endl;
        cin.ignore();
        cin.get();
    });
    
    stockMenu->addMenuItem("재고 증가/차감", []() {
        cout << "\n재고를 수정합니다..." << endl;
        cout << "아무 키나 눌러주세요..." << endl;
        cin.ignore();
        cin.get();
    });
    
    // 메뉴 구조 설정
    adminMenu->addSubMenu("제품 관리", productMenu);
    adminMenu->addSubMenu("재고 관리", stockMenu);
    
    // 메인 메뉴에 서브메뉴 추가
    mainMenu->addSubMenu("소비자", customerMenu);
    mainMenu->addSubMenu("관리자", adminMenu);
    
    // 메인 메뉴 실행
    mainMenu->run();
    
    return 0;
}