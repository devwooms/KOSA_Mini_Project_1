#ifndef SIGNUP_VIEW_H
#define SIGNUP_VIEW_H

#include "../baseScreenView.h"
#include "../../controller/screenController.h"
#include <memory>
#include <iostream>
#include <limits>
#include <string>

class signupView : public baseScreenView {
private:
    std::string id;
    std::string password;
    std::string confirmPassword;
    int currentField;  // 현재 입력 중인 필드 (0: id, 1: password, 2: confirmPassword)

public:
    signupView();
    void initialize() override;
    void display() override;
    void displayInputField(const std::string& fieldName, bool isPassword = false);
    void processInput(const std::string& input);
    bool validateInput();
    bool isPasswordMismatch() const;  // 비밀번호 불일치 확인
    void resetState() override;
};

#endif // SIGNUP_VIEW_H 