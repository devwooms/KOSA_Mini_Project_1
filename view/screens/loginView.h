#ifndef LOGIN_VIEW_H
#define LOGIN_VIEW_H

#include "../BaseScreenView.h"
#include "../../controller/UserController.h"
#include <memory>
#include <iostream>
#include <iomanip>
#include <algorithm>

class LoginView : public BaseScreenView {
private:
    std::string id;
    std::string password;
    int currentField;  // 현재 입력 중인 필드 (0: id, 1: password)
    std::shared_ptr<UserController> userCtrl;
    std::shared_ptr<User> currentUser;  // 현재 로그인된 사용자

public:
    LoginView();
    void display();  // 특별한 처리가 필요한 display 메서드
    void displayInputField(const std::string& fieldName, bool isPassword = false);
    void processInput(const std::string& input);
    bool validateInput();
    void resetState();
    std::shared_ptr<User> getCurrentUser() const { return currentUser; }
    int getCurrentField() const { return currentField; }
};

#endif // LOGIN_VIEW_H 