#ifndef SCREEN_CONTROLLER_H
#define SCREEN_CONTROLLER_H

#include <memory>
#include <stack>
#include <string>
#include <unordered_map>

class baseScreenView;

class screenController {
private:
    std::stack<std::shared_ptr<baseScreenView>> screenStack;
    std::unordered_map<std::string, std::shared_ptr<baseScreenView>> screens;

public:
    screenController();
    void run();
    void navigateTo(const std::string& screenName);
    void goBack();
    void registerScreen(const std::string& name, std::shared_ptr<baseScreenView> screen);
};

#endif // SCREEN_CONTROLLER_H 