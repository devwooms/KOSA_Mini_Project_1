#ifndef MENU_VIEW_SETTINGS_HPP
#define MENU_VIEW_SETTINGS_HPP

#include <string>
#include <vector>
#include <memory>
#include <functional>

class MenuViewSettings {
public:
    // 에러 섹션 설정
    std::vector<std::string> errorMessages;
    bool showError;

    // 타이틀 섹션 설정
    std::string title;
    std::string titleBorder;
    
    // 메뉴 섹션 설정
    struct MenuItem {
        std::string text;
        int id;
        bool isEnabled;
        std::function<void()> action;  // 메뉴 선택시 실행될 동작
        
        MenuItem(const std::string& text, int id, std::function<void()> action = nullptr, bool isEnabled = true)
            : text(text), id(id), isEnabled(isEnabled), action(action) {}
    };
    std::vector<MenuItem> menuItems;
    
    // 입력 섹션 설정
    std::string inputPrompt;
    bool showInputPrompt;
    
    // 생성자
    MenuViewSettings() 
        : showError(false)
        , title("기본 메뉴")
        , titleBorder("==========")
        , inputPrompt("메뉴를 선택하세요: ")
        , showInputPrompt(true) {}
    
    // 메서드들
    void addMenuItem(const std::string& text, int id, std::function<void()> action = nullptr, bool isEnabled = true) {
        menuItems.emplace_back(text, id, action, isEnabled);
    }
    
    void addErrorMessage(const std::string& message) {
        errorMessages.push_back(message);
        showError = true;
    }
    
    void clearErrorMessages() {
        errorMessages.clear();
        showError = false;
    }
    
    void setTitle(const std::string& newTitle) {
        title = newTitle;
        titleBorder = std::string(title.length() + 4, '=');
    }
    
    void setInputPrompt(const std::string& prompt) {
        inputPrompt = prompt;
    }

    // 메뉴 선택 처리
    bool handleChoice(int choice) {
        if (choice >= 0 && choice < static_cast<int>(menuItems.size())) {
            const auto& selectedItem = menuItems[choice];
            if (selectedItem.isEnabled && selectedItem.action) {
                selectedItem.action();
                return true;
            }
        }
        return false;
    }
};

#endif // MENU_VIEW_SETTINGS_HPP 