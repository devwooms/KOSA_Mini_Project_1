#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif
#include "adminMenu.h"

using namespace std;

// 큰 타이틀 지금 화면 나타내기
void adminTiTle(){
    string title = "관리자 페이지";
    string line(title.size() + 4, '-');
    cout << "\033[38;5;147m"; // 파란색 시작
    cout << "┌" << line << "┐" << endl;
    cout << "│     " << title << "     │" << endl;
    cout << "└" << line << "┘" << endl;
    cout << "\033[0m"; // 색상 리셋   
}

// 화면 지우기
void clearScreenAdmin() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// --------------------------------- 제품 관리 ---------------------------------
void productManagement(){
    clearScreenAdmin();
    adminTiTle();
    int adminChoice;

    cout << " === 제품 관리 === " << endl;
    cout << "1. 제품 조회" << endl;
    cout << "2. 제품 입력" << endl;
    cout << "3. 제품 수정" << endl;
    cout << "4. 제품 삭제" << endl;
    cout << "0. 뒤로 가기" << endl;
    cout << "선택: ";
    cin >> adminChoice;

    int productId;
    string name;
    string category;
    string brand;
    int price;
    float rewardpoints;
    float expirationDate;
    int wholesalePrice;
    string item;
    Product newProduct;

    switch(adminChoice){
        case 1:
            // productManagement();
            break;
        case 2:
            cout << " === 제품 입력 === " << endl;
            cout << "제품 번호: ";
            cin >> productId;
            cout << "제품 이름: ";
            cin >> name;
            cout << "제품 카테고리: ";
            cin >> category;
            cout << "제품 가격: ";
            cin >> price;
            cout << "제품 브랜드: ";
            cin >> brand;
            cout << "제품 적립 포인트: ";
            cin >> rewardpoints;
            cout << "제품 이벤트 할인: ";
            cin >> expirationDate;
            cout << "제품 업체 가격: ";
            cin >> wholesalePrice;

            newProduct = Product(productId, name, category, price, brand, rewardpoints, expirationDate, wholesalePrice);
            newProduct.info();
            cout << "제품 입력이 완료되었습니다." << endl;
            cout << "계속하시려면 아무 키나 누르세요...";
            cin.ignore();
            cin.get();
            break;
        case 3:
            // productManagement();
            break;
        case 4:
            // productManagement();
            break;
        case 0:
            return;
        default:
            cout << "잘못된 선택입니다." << endl;
            break;
    }
}

// --------------------------------- 결제 및 거래 처리 시스템 ---------------------------------
void paymentAndTransactionSystem(){
    clearScreenAdmin();
    adminTiTle();
    int adminChoice;
    cout << " === 결제 및 거래 처리 시스템 === " << endl;
    cout << "1. 상품 재고 증가/차감" << endl;
    cout << "2. 상품 주문 정보 (날짜, 수량, 유효기한)" << endl;
    cout << "3. 회원 포인트 적립/차감" << endl;
    cout << "4. 거래 내역 영수증 (날짜, 물품 항목, 시간, 금액)" << endl;
    cout << "0. 뒤로 가기" << endl;
    cout << "선택: ";
    cin >> adminChoice;

    switch(adminChoice){
        case 1:
            // paymentAndTransactionSystem();
            break;
        case 2:
            // paymentAndTransactionSystem();
            break;
        case 0:
            return;
        default:
            cout << "잘못된 선택입니다." << endl;
            break;
    }
}

// --------------------------------- 관리자 메뉴 ---------------------------------
void adminMenu(){
    int adminChoice;

    while(true){
        clearScreenAdmin();
        adminTiTle();
        cout << "1. 제품 관리" << endl;
        cout << "2. 결제 및 거래 처리 시스템" << endl;
        cout << "0. 종료" << endl;
        cout << "선택: ";
        cin >> adminChoice;

        switch(adminChoice){
            case 1:
                productManagement();
                break;
            case 2:
                paymentAndTransactionSystem();
                break;
            case 0:
                return;
            default:
                cout << "잘못된 선택입니다." << endl;
                break;
        }
    }
}