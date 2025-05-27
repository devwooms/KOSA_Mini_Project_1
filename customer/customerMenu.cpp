#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif
#include "customerMenu.h"

// 큰 타이틀 지금 화면 나타내기
void customerTiTle(){
    string title = "고객 페이지";
    string line(title.size() + 4, '-');
    cout << "\033[38;5;147m"; // 파란색 시작
    cout << "┌" << line << "┐" << endl;
    cout << "│     " << title << "     │" << endl;
    cout << "└" << line << "┘" << endl;
    cout << "\033[0m"; // 색상 리셋   
}

// 화면 지우기
void clearScreenCustomer() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// --------------------------------- 상품 구매 ---------------------------------
void purchaseProduct(){
    clearScreenCustomer();
    customerTiTle();
    int customerChoice;

    cout << " === 상품 구매 === " << endl;
    cout << "1. 상품 조회" << endl;
    cout << "2. 상품 구매" << endl;
    cout << "0. 뒤로 가기" << endl;
    cout << "선택: ";
    cin >> customerChoice;

    switch(customerChoice){
        case 1:
            // purchaseProduct();
            break;
        case 2:
            // purchaseProduct();
            break;
        case 0:
            return;
        default:
            cout << "잘못된 선택입니다." << endl;
            break;
    }
}

// --------------------------------- 포인트 조회 ---------------------------------
void checkPoints(){
    clearScreenCustomer();
    customerTiTle();
    int customerChoice;

    cout << " === 포인트 조회 === " << endl;
    cout << "1. 포인트 조회" << endl;
    cout << "2. 포인트 사용" << endl;
    cout << "0. 뒤로 가기" << endl;
    cout << "선택: ";
    cin >> customerChoice;

    switch(customerChoice){
        case 1:
            // checkPoints();
            break;
        case 2:
            // checkPoints();
            break;
        case 0:
            return;
        default:
            cout << "잘못된 선택입니다." << endl;
            break;
    }
}

// --------------------------------- 구매 내역 조회 ---------------------------------
void purchaseHistory(){
    clearScreenCustomer();
    customerTiTle();
    int customerChoice;

    cout << " === 구매 내역 조회 === " << endl;
    cout << "1. 구매 내역 조회" << endl;
    cout << "2. 구매 내역 삭제" << endl;
    cout << "0. 뒤로 가기" << endl;
    cout << "선택: ";
    cin >> customerChoice;

    switch(customerChoice){
        case 1:
            // purchaseHistory();
            break;
        case 2:
            // purchaseHistory();
            break;
        case 0:
            return;
        default:
            cout << "잘못된 선택입니다." << endl;
            break;
    }
}

// --------------------------------- 고객 메뉴 ---------------------------------
void customerMenu(){
    int customerChoice;

    while(true){
        clearScreenCustomer();
        customerTiTle();
        cout << "1. 상품 구매" << endl;
        cout << "2. 포인트 조회" << endl;
        cout << "3. 구매 내역 조회" << endl;
        cout << "0. 종료" << endl;
        cout << "선택: ";
        cin >> customerChoice;

        switch(customerChoice){
            case 1:
                purchaseProduct();
                break;
            case 2:
                checkPoints();
                break;
            case 3:
                purchaseHistory();
                break;
            case 0:
                return;
            default:
                cout << "잘못된 선택입니다." << endl;
                break;
        }
    }
}