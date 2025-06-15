#ifndef BASE_SCREEN_VIEW_H
#define BASE_SCREEN_VIEW_H

#include <string>
#include <vector>
#include <functional>
#include <memory>

// 전방 선언
class screenController;

class baseScreenView {
private:
    // 화면 제목
    std::string title;
    // 메뉴 항목들
    std::vector<std::string> menuItems;
    // 메뉴 동작들 (각 메뉴 항목에 대응)
    std::vector<std::function<void()>> menuActions;
    // 컨트롤러 참조
    screenController* controller;

public:
    baseScreenView() = default;
    virtual ~baseScreenView() = default;

    virtual void initialize() = 0;
    virtual void display() = 0;
    virtual void resetState() {}  // 상태 초기화를 위한 가상 메서드 추가

    // setters
    void setTitle(const std::string& newTitle) { title = newTitle; }
    void setMenuItems(const std::vector<std::string>& items) { menuItems = items; }
    void setMenuActions(const std::vector<std::function<void()>>& actions) { menuActions = actions; }
    void setController(screenController* ctrl) { controller = ctrl; }

    // getters
    std::string getTitle() const { return title; }
    std::vector<std::string> getMenuItems() const { return menuItems; }
    const std::vector<std::function<void()>>& getMenuActions() const { return menuActions; }
    screenController* getController() const { return controller; }

    // utility functions
    void clearScreen() const;

    void addMenuItem(const std::string& item, std::function<void()> action) {
        menuItems.push_back(item);
        menuActions.push_back(action);
    }

    void clearMenu() {
        menuItems.clear();
        menuActions.clear();
    }
};

#endif // BASE_SCREEN_VIEW_H 