#ifndef VIEW_RENDER_H
#define VIEW_RENDER_H

#include <string>
#include <vector>
#include <memory>
#include <functional>
#include "../util.hpp"

class viewRender {
public:
    // 렌더링 메서드
    static void render(const std::string& title, const std::vector<std::string>& menuItems);

private:
    // 섹션별 렌더링 메서드
    static void renderTitle(const std::string& title);
    static void renderMenuItems(const std::vector<std::string>& menuItems);
    static void clearScreen();
};

#endif // VIEW_RENDER_H 