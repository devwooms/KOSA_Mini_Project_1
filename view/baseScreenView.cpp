#include "BaseScreenView.h"
#include "../controller/ScreenController.h"
#include <iomanip>
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

// ============================================================================
// 화면 지우기
// ============================================================================
void BaseScreenView::clearScreen() const {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

// ============================================================================
// 렌더링 헬퍼 메서드들
// ============================================================================

// 타이틀 렌더링
void BaseScreenView::renderTitle(const std::string &title) const {
  const int titleLength = static_cast<int>(title.length());
  const std::string border(titleLength + 4, '=');

  std::cout << "\n\n";
  std::cout << std::setw(DEFAULT_WIDTH) << std::left << border << "\n";
  std::cout << std::setw(DEFAULT_WIDTH) << std::left << "= " + title + " ="
            << "\n";
  std::cout << std::setw(DEFAULT_WIDTH) << std::left << border << "\n\n";
}

// 메뉴 렌더링
void BaseScreenView::renderMenuItems(
    const std::vector<std::string> &menuItems) const {
  std::cout << "\n";
  for (size_t i = 0; i < menuItems.size(); ++i) {
    std::cout << std::setw(DEFAULT_WIDTH) << std::left
              << std::to_string(i + 1) + ". " + menuItems[i] << "\n";
  }
  std::cout << "\n";
}

// ============================================================================
// 기본 네비게이션 헬퍼
// ============================================================================

void BaseScreenView::goBack() {
  if (controller) {
    controller->popScreen();
  }
}