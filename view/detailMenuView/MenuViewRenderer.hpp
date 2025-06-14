#ifndef MENU_VIEW_RENDERER_HPP
#define MENU_VIEW_RENDERER_HPP

#include "MenuViewSettings.hpp"
#include "../../util.hpp"
#include <iostream>

class MenuViewRenderer {
public:
    static void renderErrorSection(const MenuViewSettings& settings) {
        if (settings.showError && !settings.errorMessages.empty()) {
            int rows, cols;
            Util::getTerminalSize(rows, cols);
            
            // 에러 메시지는 첫 번째 1/10 영역에 표시
            Util::printNLines(rows/10 - 1);
            std::cout << "\033[31m"; // 빨간색으로 변경
            for (const auto& message : settings.errorMessages) {
                Util::printLeftAligned("오류: " + message, 40, true);
            }
            std::cout << "\033[0m"; // 색상 초기화
        }
    }
    
    static void renderTitleSection(const MenuViewSettings& settings) {
        int rows, cols;
        Util::getTerminalSize(rows, cols);
        
        // 타이틀은 두 번째 2/10 영역에 표시
        if (!settings.showError) {
            Util::printNLines(2 * rows/10 - 1);
        } else {
            Util::printNLines(rows/10 - 1);
        }
        
        // 타이틀 출력
        Util::printLeftAligned(settings.titleBorder, 40, true);
        Util::printLeftAligned("===== " + settings.title + " =====", 40, true);
        Util::printLeftAligned(settings.titleBorder, 40, true);
        std::cout << std::endl;
    }
    
    static void renderMenuSection(const MenuViewSettings& settings) {
        int rows, cols;
        Util::getTerminalSize(rows, cols);
        
        // 메뉴 항목과 이전 섹션 사이의 여백
        Util::printNLines(rows/10 - 1);
        
        // 메뉴 항목 출력 (4/10 영역 사용)
        for (const auto& item : settings.menuItems) {
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
    
    static void renderInputSection(const MenuViewSettings& settings) {
        if (settings.showInputPrompt) {
            int rows, cols;
            Util::getTerminalSize(rows, cols);
            
            // 입력 커서를 화면 높이의 1/3 지점에 위치시킴
            Util::printNLines(rows/3 - settings.menuItems.size() - 5);
            
            // 입력 안내 표시
            Util::printLeftAligned(settings.inputPrompt, 40, false);
        }
    }
    
    static void renderFullMenu(const MenuViewSettings& settings) {
        Util::clearScreen();
        renderErrorSection(settings);
        renderTitleSection(settings);
        renderMenuSection(settings);
        renderInputSection(settings);
    }
};

#endif // MENU_VIEW_RENDERER_HPP 