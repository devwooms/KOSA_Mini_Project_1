#ifndef VIEW_RENDER_H
#define VIEW_RENDER_H

#include <string>
#include <vector>
#include <memory>
#include "../util.h"

class view {
public:
    virtual ~view() = default;
    virtual void initialize() = 0;
    virtual void display() = 0;
    virtual void processInput(const std::string& input) = 0;
    virtual bool validateInput() = 0;
    
    void setTitle(const std::string& newTitle) { title = newTitle; }
    std::string getTitle() const { return title; }
    
protected:
    std::string title;
};

class viewRender {
private:
    std::shared_ptr<view> currentView;
    std::vector<std::shared_ptr<view>> viewStack;
    
    static void renderTitle(const std::string& title);
    static void renderMenuItems(const std::vector<std::string>& menuItems);
    static void clearScreen();
    
public:
    static void render(const std::string& title, const std::vector<std::string>& menuItems);
    static void render(const std::string& title);

    void setView(std::shared_ptr<view> view) {
        if (view) {
            view->initialize();
            currentView = view;
        }
    }
    
    void pushView(std::shared_ptr<view> view) {
        if (currentView) {
            viewStack.push_back(currentView);
        }
        setView(view);
    }
    
    void popView() {
        if (!viewStack.empty()) {
            currentView = viewStack.back();
            viewStack.pop_back();
        }
    }
    
    void clearStack() {
        viewStack.clear();
    }
    
    void render() {
        if (currentView) {
            while (true) {
                currentView->display();
                std::string input;
                std::getline(std::cin, input);
                
                currentView->processInput(input);
                
                if (currentView->validateInput()) {
                    break;
                }
            }
        }
    }
    
    std::shared_ptr<view> getCurrentView() const {
        return currentView;
    }
};

#endif // VIEW_RENDER_H 