#ifndef BASE_SCREEN_VIEW_H
#define BASE_SCREEN_VIEW_H

#include <string>
#include <vector>
#include <functional>

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
    baseScreenView() : controller(nullptr) {}
    virtual ~baseScreenView() = default;

    // setters
    void setTitle(const std::string& newTitle);
    void setMenuItems(const std::vector<std::string>& items);
    void setMenuActions(const std::vector<std::function<void()>>& actions);
    void setController(screenController* ctrl) { controller = ctrl; }

    // getters
    std::string getTitle() const;
    std::vector<std::string> getMenuItems() const;
    const std::vector<std::function<void()>>& getMenuActions() const;
    screenController* getController() const { return controller; }

    // 화면 표시 및 입력 처리
    virtual void display() = 0;     // 화면 표시 (자식 클래스에서 반드시 구현)
    virtual int getInput() = 0;     // 사용자 입력 처리 (자식 클래스에서 반드시 구현)

    // utility functions
    void clearScreen() const;
};

#endif // BASE_SCREEN_VIEW_H 