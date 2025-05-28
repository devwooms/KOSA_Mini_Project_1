#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif
#include "../view/adminMenu.h"
#include "../controller/csvController.h"
#include "../model/entity/product/product.h"
#include "../controller/productController.h"

using namespace std;

ProductController productController;

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

    Product newProduct;
    int pkId;
    string name;
    int price;
    
    CsvController<Product> csvController;
    vector<Product> products;

    switch(adminChoice){
        case 1:
            products = productController.getAll();
            for (auto& p : products) p.info();
            cout << "제품 조회 완료" << endl;
            cout << "아무 키나 눌러주세요..." << endl;
            cin.ignore();
            cin.get();
            break;
        case 2:
            cout << "제품 번호를 입력해주세요: ";
            cin >> pkId;
            cout << "제품 이름을 입력해주세요: ";
            cin >> name;
            cout << "제품 가격을 입력해주세요: ";
            cin >> price;
            newProduct.setPkId(pkId);
            newProduct.setName(name);
            newProduct.setPrice(price);
            productController.add(newProduct);
            cout << "제품 입력 완료" << endl;
            cout << "아무 키나 눌러주세요..." << endl;
            cin.ignore();
            cin.get();
            break;
        case 3:
            products = productController.getAll();
            for (auto& p : products) p.info();
            cout << "수정할 제품의 번호를 입력해주세요: ";
            cin >> pkId;
            cout << "제품 이름을 입력해주세요: ";
            cin >> name;
            cout << "제품 가격을 입력해주세요: ";
            cin >> price;
            newProduct.setPkId(pkId);
            newProduct.setName(name);
            newProduct.setPrice(price);
            productController.update(newProduct);
            cout << "제품 수정 완료" << endl;
            cout << "아무 키나 눌러주세요..." << endl;
            cin.ignore();
            cin.get();
            break;
        case 4:
            cout << "삭제할 제품의 번호를 입력해주세요: ";
            cin >> adminChoice;
            productController.remove(adminChoice);
            cout << "제품 삭제 완료" << endl;
            cout << "아무 키나 눌러주세요..." << endl;
            cin.ignore();
            cin.get();
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
    cout << " === 재고 관리 === " << endl;
    cout << "1. 상품 재고 조회" << endl;
    cout << "2. 상품 재고 증가/차감" << endl;
    cout << "3. 상품 유통기한 조회" << endl;
    cout << "0. 뒤로 가기" << endl;
    cout << "선택: ";
    cin >> adminChoice;

    switch(adminChoice){
        case 1:
            break;
        case 2:
            break;
        case 3:
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
        cout << "2. 재고 관리" << endl;
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