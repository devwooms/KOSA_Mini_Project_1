#include "viewRender.h"
#include <iostream>
#include <limits>

// 정적 멤버 변수 초기화
std::string viewRender::currentTitle = "기본 메뉴";
std::string viewRender::titleBorder = "==========";
std::vector<viewRender::MenuItem> viewRender::menuItems;
std::vector<std::string> viewRender::errorMessages;
std::string viewRender::inputPrompt = "메뉴를 선택하세요: ";
bool viewRender::showError = false;

void viewRender::setTitle(const std::string& title) {
    currentTitle = title;
    titleBorder = std::string(title.length() + 4, '=');
}

void viewRender::setMenuItems(const std::vector<MenuItem>& items) {
    menuItems = items;
}

void viewRender::setErrorMessages(const std::vector<std::string>& messages) {
    errorMessages = messages;
    showError = !messages.empty();
}

void viewRender::addErrorMessage(const std::string& message) {
    errorMessages.push_back(message);
    showError = true;
}

void viewRender::clearErrorMessages() {
    errorMessages.clear();
    showError = false;
}

void viewRender::renderErrorSection() {
    if (showError && !errorMessages.empty()) {
        int rows, cols;
        Util::getTerminalSize(rows, cols);
        
        // 에러 메시지는 첫 번째 1/10 영역에 표시
        Util::printNLines(rows/10 - 1);
        std::cout << "\033[31m"; // 빨간색으로 변경
        for (const auto& message : errorMessages) {
            Util::printLeftAligned("오류: " + message, 40, true);
        }
        std::cout << "\033[0m"; // 색상 초기화
    }
}

void viewRender::renderTitleSection() {
    int rows, cols;
    Util::getTerminalSize(rows, cols);
    
    // 타이틀은 두 번째 2/10 영역에 표시
    if (!showError) {
        Util::printNLines(2 * rows/10 - 1);
    } else {
        Util::printNLines(rows/10 - 1);
    }
    
    // 타이틀 출력
    Util::printLeftAligned(titleBorder, 40, true);
    Util::printLeftAligned("===== " + currentTitle + " =====", 40, true);
    Util::printLeftAligned(titleBorder, 40, true);
    std::cout << std::endl;
}

void viewRender::renderMenuSection() {
    int rows, cols;
    Util::getTerminalSize(rows, cols);
    
    // 메뉴 항목과 이전 섹션 사이의 여백
    Util::printNLines(rows/10 - 1);
    
    // 메뉴 항목 출력 (4/10 영역 사용)
    for (const auto& item : menuItems) {
        std::string menuItem = std::to_string(item.id) + ".  " + item.text;
        if (!item.isEnabled) {
            std::cout << "\033[2m"; // 흐리게
        }
        Util::printLeftAligned(menuItem, 40, true);
        if (!item.isEnabled) {
            std::cout << "\033[0m"; // 스타일 초기화
        }
    }
    std::cout << std::endl;
}

void viewRender::renderInputSection() {
    int rows, cols;
    Util::getTerminalSize(rows, cols);
    
    // 입력 커서를 화면 높이의 1/3 지점에 위치시킴
    Util::printNLines(rows/3 - menuItems.size() - 5);
    
    // 입력 안내 표시
    Util::printLeftAligned(inputPrompt, 40, false);
}

void viewRender::render() {
    Util::clearScreen();
    renderErrorSection();
    renderTitleSection();
    renderMenuSection();
    renderInputSection();
}

int viewRender::getInput() {
    int choice;
    std::cin >> choice;
    
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;  // 잘못된 입력
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
} 