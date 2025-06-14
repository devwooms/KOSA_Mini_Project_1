#ifndef SCREEN_CONTROLLER_H
#define SCREEN_CONTROLLER_H

#include "../view/baseScreenView.h"
#include "../view/screens/TestView1.hpp"
#include "../view/screens/TestView2.hpp"
#include "../view/screens/TestView3.hpp"
#include <memory>
#include <unordered_map>
#include <stack>

class screenController {
public:
    screenController();
    void run();

    // 화면 전환 및 관리 메서드들
    void navigateTo(const std::string& viewId);  // 새로운 화면으로 이동
    void goBack();                               // 이전 화면으로 돌아가기
    bool canGoBack() const;                      // 뒤로 갈 수 있는지 확인
    void clearStackAndNavigateTo(const std::string& viewId);  // 스택 초기화 후 새로운 화면으로 이동

private:
    // 화면 전환 내부 구현
    void transitionTo(std::shared_ptr<baseScreenView> view);
    std::shared_ptr<baseScreenView> createView(const std::string& viewId);

    // 화면 저장소
    std::unordered_map<std::string, std::shared_ptr<baseScreenView>> viewRegistry;
    std::stack<std::shared_ptr<baseScreenView>> viewStack;
};

#endif // SCREEN_CONTROLLER_H 