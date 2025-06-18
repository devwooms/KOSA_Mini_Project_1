#ifndef ADMIN_MENU_H
#define ADMIN_MENU_H

#include "../controller/productController.h"
#include "../controller/stockController.h"

// 전역 변수 선언
extern ProductController productController;
extern StockController stockController;

// 큰 타이틀 지금 화면 나타내기
void adminTiTle();

// 화면 지우기
void clearScreenAdmin();

// 제품 관리
void productManagement();

// 결제 및 거래 처리 시스템
void paymentAndTransactionSystem();

// 관리자 메뉴
void adminMenu();

#endif
