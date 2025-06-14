#ifndef VIEW_SETTING_H
#define VIEW_SETTING_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <functional>

class ViewSetting {
private:
    std::string title;
    std::vector<std::pair<std::string, std::function<void()>>> menuItems;
    std::vector<std::shared_ptr<ViewSetting>> subMenus;
    ViewSetting* parent;

    void clearScreen() const;
    void displayTitle() const;
    void displayMenu() const;
    void handleInput();

public:
    ViewSetting(const std::string& title, ViewSetting* parent = nullptr);
    
    // 메뉴 아이템 추가 메서드
    void addMenuItem(const std::string& label, std::function<void()> action);
    
    // 서브메뉴 추가 메서드
    void addSubMenu(const std::string& label, std::shared_ptr<ViewSetting> subMenu);
    
    // 메뉴 실행 메서드
    void run();
    
    // 부모 메뉴로 돌아가기
    ViewSetting* getParent() const;
};

#endif // VIEW_SETTING_H
