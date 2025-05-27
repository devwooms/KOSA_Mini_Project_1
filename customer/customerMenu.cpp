#include <iostream>
#include "customerMenu.h"

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