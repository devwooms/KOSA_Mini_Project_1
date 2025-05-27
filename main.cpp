#include <iostream>

int main() {
    int choice;


    std::cout << "1. 고객 관리" << std::endl;
    std::cout << "2. 제품 관리" << std::endl;
    std::cout << "3. 종료" << std::endl;

    std::cin >> choice;

    switch(choice) {
        case 1:
            std::cout << "고객 관리" << std::endl;
            break;
        case 2:
            std::cout << "제품 관리" << std::endl;
            break;
        case 3:
            std::cout << "종료" << std::endl;
            return 0;
        default:
            std::cout << "잘못된 선택입니다." << std::endl;
            break;
    }


    
    return 0;
} 