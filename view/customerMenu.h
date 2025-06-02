#ifndef CUSTOMER_MENU_H
#define CUSTOMER_MENU_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void clearScreen();
void customerTiTle();

void customerMenu(){
    int customerChoice;
    clearScreen();
    customerTiTle();
    std::cout << "=== 소비자 메뉴 ===" << std::endl;
    std::cout << "1. 상품 조회" << std::endl;
    std::cout << "0. 종료" << std::endl;
}

#endif