#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif
#include "../view/adminMenu.h"
#include "../model/entity/product/product.h"
#include "../controller/productController.h"
#include "../controller/stockController.h"
#include "../utils/validator.h"

using namespace std;

ProductController productController;
StockController stockController;


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

    Product product;
    int pkId;
    string name;
    int price;
    
    vector<Product> products;

    cout << " === 제품 관리 === " << endl;
    cout << "1. 제품 조회" << endl;
    cout << "2. 제품 입력" << endl;
    cout << "3. 제품 수정" << endl;
    cout << "4. 제품 삭제" << endl;
    cout << "0. 뒤로 가기" << endl;
    cout << "선택: ";
    cin >> adminChoice;



    switch(adminChoice){
        case 1:
            products = productController.getAll(product);
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
            product.setPkId(pkId);
            product.setName(name);
            product.setPrice(price);
            productController.add(product);
            cout << "제품 입력 완료" << endl;
            cout << "아무 키나 눌러주세요..." << endl;
            cin.ignore();
            cin.get();
            break;
        case 3:
            products = productController.getAll(product);
            for (auto& p : products) p.info();
            cout << "수정할 제품의 번호를 입력해주세요: ";
            cin >> pkId;
            cout << "제품 이름을 입력해주세요: ";
            cin >> name;
            cout << "제품 가격을 입력해주세요: ";
            cin >> price;
            product.setPkId(pkId);
            product.setName(name);
            product.setPrice(price);
            productController.update(product);
            cout << "제품 수정 완료" << endl;
            cout << "아무 키나 눌러주세요..." << endl;
            cin.ignore();
            cin.get();
            break;
        case 4:
            cout << "삭제할 제품의 번호를 입력해주세요: ";
            cin >> adminChoice;
            product.setPkId(adminChoice);
            productController.remove(product);
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

// --------------------------------- 재고 관리 시스템 ---------------------------------
void paymentAndTransactionSystem(){
    clearScreenAdmin();
    adminTiTle();
    int adminChoice;

    Product product;
    Stock stock;
    int pkId;
    int quantity;
    string expirationDate;
    vector<Stock> stocks;

    cout << " === 재고 관리 === " << endl;
    cout << "1. 상품 재고 조회" << endl;
    cout << "2. 상품 재고 입력" << endl;
    cout << "3. 상품 재고 증가/차감" << endl;
    cout << "4. 상품 유통기한 조회" << endl;
    cout << "0. 뒤로 가기" << endl;
    cout << "선택: ";
    cin >> adminChoice;

    switch(adminChoice){
        case 1:
            stocks = stockController.getAll(stock);
            for (auto& s : stocks) s.info();
            cout << "재고 조회 완료" << endl;
            cout << "아무 키나 눌러주세요..." << endl;
            cin.ignore();
            cin.get();
            break;
        case 2:
            cout << "상품 번호를 입력해주세요: ";
            cin >> pkId;
            product = productController.get(pkId);
            // 상품이 존재하지 않는 경우
            if (product.getPkId() == 0) {
                cout << "상품이 존재하지 않습니다." << endl;
                cout << "아무 키나 눌러주세요..." << endl;
                cin.ignore();
                cin.get();
                return;
            } 
            // 상품이 존재하는 경우
            else {
                product.info();
                cout << "이 제품이 맞습니까? (y/n): ";
                char confirm;
                cin >> confirm;
                if (confirm == 'y') {
                    cout << "상품 재고를 입력해주세요: ";
                    cin >> quantity;
                    stock.setPkId(pkId);
                    stock.setQuantity(quantity);
                    while(true){
                        cout << "상품 유통기한을 입력해주세요(예: 2025-01-01): ";
                        cin >> expirationDate;
                        if (Validator::isValidDate(expirationDate)) {
                            break;
                        } else {
                            cout << "유통기한 형식이 올바르지 않습니다." << endl;
                        }
                    }
                    stock.setExpirationDate(expirationDate);
                    stock.setProduct(product);
                    stockController.add(stock);
                    cout << "상품 재고 입력 완료" << endl;
                    cout << "아무 키나 눌러주세요..." << endl;
                    cin.ignore();
                    cin.get();
                } else {
                    cout << "상품 재고 입력 취소" << endl;
                    cout << "아무 키나 눌러주세요..." << endl;
                    cin.ignore();
                    cin.get();
                }
            }
            break;
        case 3:
            cout << "상품 재고 증가/차감" << endl;
            cout << "상품 번호를 입력해주세요: ";
            cin >> pkId;
            stock = stockController.get(pkId);
            if (stock.getPkId() == 0) {
                cout << "상품이 존재하지 않습니다." << endl;
                cout << "아무 키나 눌러주세요..." << endl;
                cin.ignore();
                cin.get();
                return;
            } else {
                stock.info();
                cout << "현재 재고 수량: " << stock.getQuantity() << "개" << endl;
                cout << "재고 수량 변경 (증가: +n, 감소: -n): ";
                cin >> quantity;
                
                // 기존 수량에 입력받은 값을 더함
                int newQuantity = stock.getQuantity() + quantity;
                
                // 재고가 음수가 되지 않도록 체크
                if (newQuantity < 0) {
                    cout << "재고가 부족합니다." << endl;
                    cout << "아무 키나 눌러주세요..." << endl;
                    cin.ignore();
                    cin.get();
                    return;
                }
                
                stock.setQuantity(newQuantity);
                stockController.update(stock);
                cout << "재고 수량이 " << stock.getQuantity() << "개로 변경되었습니다." << endl;
                cout << "아무 키나 눌러주세요..." << endl;
                cin.ignore();
                cin.get();
            }
            
            break;
        case 4:
            stocks = stockController.getAll(stock);
            for (auto& s : stocks) s.info();
            cout << "재고 조회 완료" << endl;
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