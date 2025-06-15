#include "viewRender.h"
#include <iostream>
#include <limits>
#include <iomanip>



// 타이틀 렌더링
void viewRender::renderTitle(const std::string& title) {
    int titleLength = title.length();
    std::string border(titleLength + 4, '=');  
    
    std::cout << "\n\n";  
    std::cout << std::setw(40) << std::left << border << "\n";
    std::cout << std::setw(40) << std::left << "= " + title + " =" << "\n";
    std::cout << std::setw(40) << std::left << border << "\n\n";
}

void viewRender::renderMenuItems(const std::vector<std::string>& menuItems) {
    std::cout << "메뉴 선택:\n\n";
    for (size_t i = 0; i < menuItems.size(); ++i) {
        std::cout << std::setw(40) << std::left 
                  << std::to_string(i + 1) + ". " + menuItems[i] << "\n";
    }
    std::cout << "\n";
}

// 모두 지우기
void viewRender::clearScreen() {
    std::cout << "\033[2J\033[H"; 
}

// 렌더링
void viewRender::render(const std::string& title, const std::vector<std::string>& menuItems) {
    clearScreen();
    renderTitle(title);
    renderMenuItems(menuItems);
}
