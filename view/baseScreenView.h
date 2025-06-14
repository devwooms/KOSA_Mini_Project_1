#ifndef BASE_SCREEN_VIEW_HPP
#define BASE_SCREEN_VIEW_HPP

#include <string>
#include <vector>
#include <memory>
#include <functional>

class baseScreenView {
protected:
    // 화면 제목
    std::string title;
    // 메뉴 항목들
    std::vector<std::string> menuItems;
    // 메뉴 동작 함수
    std::function<void()> menuAction;

public:
    baseScreenView() = default;
    virtual ~baseScreenView() = default;

    // setters
    void setTitle(const std::string& newTitle);
    void setMenuItems(const std::vector<std::string>& items);
    void setMenuAction(std::function<void()> action);

    // getters
    std::string getTitle() const;
    std::vector<std::string> getMenuItems() const;
    std::function<void()> getMenuAction() const;

    // 화면 표시 및 입력 처리 (순수 가상 함수)
    virtual void display() = 0;     // 화면 표시 (자식 클래스에서 반드시 구현)
    virtual int getInput() = 0;     // 사용자 입력 처리 (자식 클래스에서 반드시 구현)
};

#endif // BASE_SCREEN_VIEW_HPP 