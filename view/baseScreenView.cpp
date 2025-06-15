#include "baseScreenView.h"
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

// setters
void baseScreenView::setTitle(const std::string& newTitle) { title = newTitle; }
void baseScreenView::setMenuItems(const std::vector<std::string>& items) { menuItems = items; }
void baseScreenView::setMenuActions(const std::vector<std::function<void()>>& actions) { menuActions = actions; }

// getters
std::string baseScreenView::getTitle() const { return title; }
std::vector<std::string> baseScreenView::getMenuItems() const { return menuItems; }
const std::vector<std::function<void()>>& baseScreenView::getMenuActions() const { return menuActions; }

// ---- 기타 함수들 ----
void baseScreenView::clearScreen() const { std::cout << "\033[2J\033[H"; }