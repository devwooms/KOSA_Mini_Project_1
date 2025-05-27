#include <iostream>
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
std::cout << "원하는 서비스의 번호를 선택하세요" << std::endl;
    std::cout << "1. 제품 종류" << std::endl;
    std::cout << "2. 제품 구매" << std::endl;
    std::cout << "3. 제품 장바구니" << std::endl;
    std::cout << "4. 제품 구매 내역" << std::endl;
    std::cout << "5. 제품 후기" << std::endl;
    std::cout << "6. 제품 후기 내역" << std::endl;
    std::cout << "7. 뒤로 되돌아가기" << std::endl;
    
    char SelectNum;
    std::cin >> SelectNum;

    switch(SelectNum){
        
        case '1':
        std::cout << "1번 선택" << std::endl;
        break;
        
        case '2':
        std::cout << "2번 선택" << std::endl;
        break;
        
        case '3':
        std::cout << "3번 선택" << std::endl;
        break;

        case '4':
        std::cout << "4번 선택" << std::endl;
        break;

        case '5':
        std::cout << "5번 선택" << std::endl;
        break;

        case '6':
        std::cout << "6번 선택" << std::endl;
        break;

        case '7':
        std::cout << "7번 선택" << std::endl;
        break;

        default:
        std::cout << "잘못된 선택입니다" << std::endl;
        break;
    }
}