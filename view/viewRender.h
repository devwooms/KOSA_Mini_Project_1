#ifndef VIEW_RENDER_H
#define VIEW_RENDER_H

#include <string>
#include <vector>
#include <memory>
#include <functional>
#include "../util.hpp"

class viewRender {
public:
    struct MenuItem {
        std::string text;
        int id;
        bool isEnabled;
        std::function<void()> action;

        MenuItem(const std::string& text, int id, std::function<void()> action = nullptr, bool isEnabled = true)
            : text(text), id(id), isEnabled(isEnabled), action(action) {}
    };

    // 렌더링 설정 관련 메서드
    static void setTitle(const std::string& title);
    static void setMenuItems(const std::vector<MenuItem>& items);
    static void setErrorMessages(const std::vector<std::string>& messages);
    static void addErrorMessage(const std::string& message);
    static void clearErrorMessages();

    // 렌더링 메서드
    static void render();
    static int getInput();

private:
    // 섹션별 렌더링 메서드
    static void renderErrorSection();
    static void renderTitleSection();
    static void renderMenuSection();
    static void renderInputSection();

    // 내부 상태
    static std::string currentTitle;
    static std::string titleBorder;
    static std::vector<MenuItem> menuItems;
    static std::vector<std::string> errorMessages;
    static std::string inputPrompt;
    static bool showError;
};

#endif // VIEW_RENDER_H 