#ifndef SIGNUP_VIEW_H
#define SIGNUP_VIEW_H

#include "../../controller/UserController.h"
#include "../BaseScreenView.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <memory>

class SignupView : public BaseScreenView {
private:
  std::string id;
  std::string password;
  std::string confirmPassword;
  int currentField; // 현재 입력 중인 필드 (0: id, 1: password, 2: confirmPassword)
  std::shared_ptr<UserController> userCtrl;

public:
  SignupView();
  void display(); // 특별한 처리가 필요한 display 메서드
  void displayInputField(const std::string &fieldName, bool isPassword = false);
  void processInput(const std::string &input);
  bool validateInput();
  bool isPasswordMismatch() const; // 비밀번호 불일치 확인
  void resetState();
  bool registerUser(); // 사용자 등록 메서드 추가
};

#endif // SIGNUP_VIEW_H