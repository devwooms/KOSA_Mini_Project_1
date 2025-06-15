#ifndef BASE_SCREEN_VIEW_H
#define BASE_SCREEN_VIEW_H

#include <functional>
#include <memory>
#include <string>
#include <vector>

// 전방 선언
class ScreenController;

class BaseScreenView {
private:
  static const int DEFAULT_WIDTH = 50; // 렌더링 폭 설정

  int showError = 0;
  // 오류 안내
  std::vector<std::string> errorMessages;
  // 화면 제목
  std::string title;
  // 메뉴 항목들
  std::vector<std::string> menuItems;
  // 메뉴 동작들 (각 메뉴 항목에 대응)
  std::vector<std::function<void()>> menuActions;
  // 컨트롤러 참조
  ScreenController *controller;

protected:
  // 렌더링 메서드들
  void renderTitle(const std::string &title) const;
  void renderMenuItems(const std::vector<std::string> &menuItems) const;
  void renderErrorMessages(const std::string &errorMessage) const;
  // 기본 네비게이션 헬퍼
  void goBack();
  void goToScreen(std::shared_ptr<BaseScreenView> screen);

public:
  BaseScreenView() = default;
  virtual ~BaseScreenView() = default;

  // setters
  void setShowError(int showError) { this->showError = showError; }
  void setErrorMessages(const std::vector<std::string> &messages) { errorMessages = messages; }
  void setTitle(const std::string &newTitle) { title = newTitle; }
  void setMenuItems(const std::vector<std::string> &items) { menuItems = items; }
  void setMenuActions(const std::vector<std::function<void()>> &actions) { menuActions = actions; }
  void setController(ScreenController *ctrl) { controller = ctrl; }

  // getters
  int getShowError() const { return showError; }
  const std::vector<std::string> &getErrorMessages() const { return errorMessages; }
  std::string getTitle() const { return title; }
  std::vector<std::string> getMenuItems() const { return menuItems; }
  const std::vector<std::function<void()>> &getMenuActions() const { return menuActions; }
  ScreenController *getController() const { return controller; }

  /* ================================================ */
  /* 화면 관련 메서드들 */
  /* ================================================ */
  // 화면 지우기
  void clearScreen() const;
  // 각 화면의 실행 로직 (가상 메서드)
  virtual void run() {}

};

#endif // BASE_SCREEN_VIEW_H