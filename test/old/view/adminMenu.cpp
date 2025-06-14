#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif
#include "adminMenu.h"
#include "../model/entity/product/product.h"
#include "../model/entity/product/drink.h"
#include "../model/entity/product/instantMeal.h"
#include "../model/entity/product/tobacoo.h"
#include "../model/productFactory.h"
#include "../controller/productController.h"
#include "../controller/stockController.h"
#include "../utils/validator.h"

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

    vector<shared_ptr<Product>> products = productController.getAll();
    shared_ptr<Product> product;  // raw pointer를 shared_ptr로 변경
    int pkId;
    string name;
    int price;
    string type;
    
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
            for (const auto& product : products) {
                product->info();
            }
            cout << "제품 조회 완료" << endl;
            cout << "아무 키나 눌러주세요..." << endl;
            cin.ignore();
            cin.get();
            break;
        case 2: {
            cout << "제품 번호를 입력해주세요(취소 0): ";
            cin >> pkId;

            if (pkId <= 0) {
                cout << "취소합니다." << endl;
                cout << "아무 키나 눌러주세요..." << endl;
                cin.ignore();
                cin.get();
                break;
            }

            // 중복 체크
            auto existingProduct = productController.get(pkId);
            if (existingProduct) {
                cout << "이미 존재하는 제품입니다:" << endl;
                existingProduct->info();  // 기존 제품 정보 출력
                cout << "\n아무 키나 눌러주세요..." << endl;
                cin.ignore();
                cin.get();
                break;
            }

            cout << "제품 이름을 입력해주세요: ";
            cin >> name;
            cout << "제품 가격을 입력해주세요: ";
            cin >> price;
            
            cout << "\n=== 제품 타입 선택 ===" << endl;
            cout << "1. 음료 (Drink)" << endl;
            cout << "2. 즉석식품 (InstantMeal)" << endl;
            cout << "3. 담배 (Tobacco)" << endl;
            cout << "선택: ";
            cin >> adminChoice;

            switch(adminChoice) {
                case 1: {
                    cout << "탄산 여부 (1: 있음, 0: 없음): ";
                    string isCarbonated;
                    cin >> isCarbonated;
                    map<string, string> attributes{{"isCarbonated", isCarbonated}};
                    product = productController.createProduct(pkId, name, price, "DRINK", attributes);
                    break;
                }
                case 2: {
                    cout << "냉동 여부 (1: 있음, 0: 없음): ";
                    string isFrozen;
                    cin >> isFrozen;
                    map<string, string> attributes{{"isFrozen", isFrozen}};
                    product = productController.createProduct(pkId, name, price, "INSTANT_MEAL", attributes);
                    break;
                }
                case 3: {
                    cout << "브랜드를 입력해주세요: ";
                    string brand;
                    cin >> brand;
                    map<string, string> attributes{{"brand", brand}};
                    product = productController.createProduct(pkId, name, price, "TOBACCO", attributes);
                    break;
                }
                default:
                    cout << "잘못된 선택입니다." << endl;
                    return;
            }

            if (product) {
                productController.add(product);
                cout << "제품 입력 완료" << endl;
            }
            
            cout << "아무 키나 눌러주세요..." << endl;
            cin.ignore();
            cin.get();
            break;
        }
        case 3: {
            products = productController.getAll();
            for (const auto& p : products) {
                p->info();
            }
            cout << "수정할 제품의 번호를 입력해주세요(취소 0): ";
            cin >> pkId;

            if (pkId <= 0) {
                cout << "취소합니다." << endl;
                cout << "아무 키나 눌러주세요..." << endl;
                cin.ignore();
                cin.get();
                break;
            }

            // 기존 제품 정보 가져오기
            auto existingProduct = productController.get(pkId);
            if (!existingProduct) {
                cout << "해당 제품이 존재하지 않습니다." << endl;
                cout << "아무 키나 눌러주세요..." << endl;
                cin.ignore();
                cin.get();
                break;
            }

            string existingType = existingProduct->getProductType();
            cout << "\n=== 현재 제품 정보 ===" << endl;
            existingProduct->info();
            cout << "\n=== 새로운 정보 입력 ===" << endl;
            
            cout << "제품 이름을 입력해주세요: ";
            cin >> name;
            cout << "제품 가격을 입력해주세요: ";
            cin >> price;
            cout << "\n=== 제품 타입 선택 ===" << endl;
            cout << "1. 음료 (Drink)" << endl;
            cout << "2. 즉석식품 (InstantMeal)" << endl;
            cout << "3. 담배 (Tobacco)" << endl;
            cout << "선택: ";
            cin >> adminChoice;

            shared_ptr<Product> updatedProduct;

            switch(adminChoice) {
                case 1: {
                    cout << "탄산 여부 (1: 있음, 0: 없음): ";
                    string isCarbonated;
                    cin >> isCarbonated;
                    map<string, string> attributes{{"isCarbonated", isCarbonated}};
                    updatedProduct = productController.createProduct(pkId, name, price, "DRINK", attributes);
                    break;
                }
                case 2: {
                    cout << "냉동 여부 (1: 있음, 0: 없음): ";
                    string isFrozen;
                    cin >> isFrozen;
                    map<string, string> attributes{{"isFrozen", isFrozen}};
                    updatedProduct = productController.createProduct(pkId, name, price, "INSTANT_MEAL", attributes);
                    break;
                }
                case 3: {
                    cout << "브랜드를 입력해주세요: ";
                    string brand;
                    cin >> brand;
                    map<string, string> attributes{{"brand", brand}};
                    updatedProduct = productController.createProduct(pkId, name, price, "TOBACCO", attributes);
                    break;
                }
                default:
                    cout << "잘못된 선택입니다." << endl;
                    return;
            }

            if (updatedProduct) {
                productController.update(updatedProduct);
                cout << "제품이 성공적으로 수정되었습니다." << endl;
                cout << "\n=== 수정된 제품 정보 ===" << endl;
                updatedProduct->info();
            } else {
                cout << "제품 수정에 실패했습니다." << endl;
            }
            
            cout << "\n아무 키나 눌러주세요..." << endl;
            cin.ignore();
            cin.get();
            break;
        }
        case 4:
            products = productController.getAll();
            for (const auto& p : products) {
                p->info();
            }
            cout << "삭제할 제품의 번호를 입력해주세요: ";
            cin >> pkId;
            product = productController.get(pkId);
            if (product) {
                productController.remove(product);
            } else {
                cout << "해당 제품이 존재하지 않습니다." << endl;
            }
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

    vector<shared_ptr<Product>> products = productController.getAll();
    shared_ptr<Product> product;  
    int pkId;

    vector<shared_ptr<Stock>> stocks = stockController.getAll();
    shared_ptr<Stock> stock;
    int quantity;
    string expirationDate;


    cout << " === 재고 관리 === " << endl;
    cout << "1. 상품 재고 조회" << endl;
    cout << "2. 상품 재고 입력" << endl;
    cout << "3. 상품 재고 증가/차감" << endl;
    cout << "0. 뒤로 가기" << endl;
    cout << "선택: ";
    cin >> adminChoice;

    switch(adminChoice){
        case 1:
            for (const auto& stock : stocks) {
                stock->info();
            }
            cout << "재고 조회 완료" << endl;
            cout << "아무 키나 눌러주세요..." << endl;
            cin.ignore();
            cin.get();
            break;
        case 2:
            products = productController.getAll();
            for (const auto& p : products) {
                p->info();
            }
            cout << "상품 번호를 입력해주세요: ";
            cin >> pkId;
            product = productController.get(pkId);
            if (!product) {
                cout << "상품이 존재하지 않습니다." << endl;
                cout << "아무 키나 눌러주세요..." << endl;
                cin.ignore();
                cin.get();
                break;
            }
            stock = stockController.get(pkId);
            if (stock) {
                cout << "이미 존재하는 상품입니다." << endl;
                stock->info();
                cout << "아무 키나 눌러주세요..." << endl;
                cin.ignore();
                cin.get();
                break;
            }
            
            product->info();  // 상품 정보만 보여줌
            cout << "이 상품이 맞습니까? (y/n): ";
            char confirm;
            cin >> confirm;
            if (confirm == 'y') {
                cout << "상품 재고를 입력해주세요: ";
                cin >> quantity;
                cout << "상품 유통기한을 입력해주세요: ";
                cin >> expirationDate;
                stock = make_shared<Stock>(pkId, product->getName(), product->getPrice(), quantity, expirationDate);
                stockController.add(stock);
                cout << "상품 재고 입력 완료" << endl;
                cout << "아무 키나 눌러주세요..." << endl;
                cin.ignore();
                cin.get();
                break;
            } else {
                cout << "상품 재고 입력 취소" << endl;
                cout << "아무 키나 눌러주세요..." << endl;
                cin.ignore();
                cin.get();
                break;
            }
            break;
        case 3:
            stocks = stockController.getAll();
            for (const auto& s : stocks) {
                s->info();
            }
            cout << "상품 번호를 입력해주세요: ";
            cin >> pkId;
            stock = stockController.get(pkId);
            if (!stock){
                cout << "상품이 존재하지 않습니다." << endl;
                cout << "아무 키나 눌러주세요..." << endl;
                cin.ignore();
                cin.get();
                break;
            }
            cout << "상품 재고 증가/차감" << endl;
            cout << "상품 재고 증가/차감 수량: ";
            cin >> quantity;
            stock->setQuantity(stock->getQuantity() + quantity);
            stockController.update(stock);
            cout << "상품 재고 증가/차감 완료" << endl;
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