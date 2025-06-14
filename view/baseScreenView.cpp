#include "baseScreenView.h"
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

// setters
void baseScreenView::setTitle(const std::string& newTitle) { title = newTitle; }
void baseScreenView::setMenuItems(const std::vector<std::string>& items) { menuItems = items; }
void baseScreenView::setMenuAction(std::function<void()> action) { menuAction = action; }

// getters
std::string baseScreenView::getTitle() const { return title; }
std::vector<std::string> baseScreenView::getMenuItems() const { return menuItems; }
std::function<void()> baseScreenView::getMenuAction() const { return menuAction; }
