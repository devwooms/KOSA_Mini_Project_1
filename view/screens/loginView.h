#ifndef LOGIN_VIEW_H
#define LOGIN_VIEW_H

#include "../baseScreenView.h"
#include "../../controller/screenController.h"
#include "../../controller/userController.h"
#include <memory>
#include <iostream>
#include <limits>

class loginView : public baseScreenView {
private:
    std::string id;
    std::string password;
    int currentField;  // 현재 입력 중인 필드 (0: id, 1: password)
    std::shared_ptr<userController> userCtrl;
    std::shared_ptr<User> currentUser;  // 현재 로그인된 사용자

public:
    loginView();
    void initialize() override;
    void display() override;
    void displayInputField(const std::string& fieldName, bool isPassword = false);
    void processInput(const std::string& input);
    bool validateInput();
    void resetState() override;
    std::shared_ptr<User> getCurrentUser() const { return currentUser; }
    int getCurrentField() const { return currentField; }
};

#endif // LOGIN_VIEW_H 