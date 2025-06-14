#ifndef TEST_VIEW_3_HPP
#define TEST_VIEW_3_HPP

#include "../baseScreenView.h"
#include <memory>
#include <iostream>
#include <limits>

class TestView3 : public baseScreenView {
public:
    TestView3() { initialize(); }

    void initialize() {
        setTitle("테스트 화면 3");
        // 메뉴 항목 설정
        setMenuItems({
            "테스트 화면 1로 이동",
            "테스트 화면 2로 이동"
        });
    }

    // baseScreenView의 순수 가상 함수 구현
    void display() override {
        std::cout << "\033[2J\033[H";  // 화면 지우기
        std::cout << "=== " << getTitle() << " ===" << std::endl << std::endl;
        
        auto items = getMenuItems();
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << (i + 1) << ". " << items[i] << std::endl;
        }
        std::cout << "0. 뒤로 가기" << std::endl;
    }

    int getInput() override {
        int choice;
        std::cout << "\n선택하세요: ";
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -1;  // 잘못된 입력
        }
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return choice;
    }
};

#endif // TEST_VIEW_3_HPP 