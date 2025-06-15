#ifndef SCREEN_CONTROLLER_H
#define SCREEN_CONTROLLER_H

#include <memory>
#include <stack>
#include <string>
#include "../view/BaseScreenView.h"

class ScreenController {
private:
    std::stack<std::shared_ptr<BaseScreenView>> screenStack;

public:
    ScreenController() = default;
    
    // 스택 관리 메서드들
    void pushScreen(std::shared_ptr<BaseScreenView> screen);
    void popScreen();
    void replaceScreen(std::shared_ptr<BaseScreenView> screen);
    void clearStack();
    
    // 현재 화면 실행
    void run();
    
    // 접근자
    std::shared_ptr<BaseScreenView> getCurrentScreen() const;
    bool hasScreens() const;
    size_t getStackSize() const;
};

#endif // SCREEN_CONTROLLER_H 