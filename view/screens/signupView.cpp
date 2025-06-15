#include "SignupView.h"


SignupView::SignupView() : currentField(0), userCtrl(std::make_shared<UserController>()) {
    setTitle("회원가입");
    resetState();
}

void SignupView::resetState() {
    id = "";
    password = "";
    confirmPassword = "";
    currentField = 0;
}

void SignupView::display() {
    clearScreen();
    
    // 타이틀 표시
    std::string title = getTitle();
    std::string border(title.length() + 4, '=');
    std::cout << "\n" << border << "\n";
    std::cout << "= " << title << " =\n";
    std::cout << border << "\n\n";

    std::cout << "회원가입을 위해 다음 정보를 입력해주세요.\n\n";
    
    // 현재까지 입력된 정보 표시
    if (!id.empty()) {
        std::cout << "아이디: " << id << "\n";
    }
    if (!password.empty()) {
        std::cout << "비밀번호: " << std::string(password.length(), '*') << "\n";
    }
    if (!confirmPassword.empty()) {
        std::cout << "비밀번호 확인: " << std::string(confirmPassword.length(), '*') << "\n";
    }
    std::cout << "\n";

    // 현재 입력해야 할 필드 표시
    switch (currentField) {
        case 0:
            displayInputField("아이디");
            break;
        case 1:
            displayInputField("비밀번호", true);
            break;
        case 2:
            displayInputField("비밀번호 확인", true);
            break;
    }
}

void SignupView::displayInputField(const std::string& fieldName, bool isPassword) {
    std::cout << fieldName << "을(를) 입력하세요: ";
}

void SignupView::processInput(const std::string& input) {
    switch (currentField) {
        case 0:
            id = input;
            break;
        case 1:
            password = input;
            break;
        case 2:
            confirmPassword = input;
            break;
    }
    currentField++;
}

bool SignupView::validateInput() {
    if (id.empty() || password.empty() || confirmPassword.empty()) {
        return false;
    }
    if (password != confirmPassword) {
        return false;
    }
    if (userCtrl->isUserIdExists(id)) {
        std::cout << "\n이미 존재하는 아이디입니다!\n";
        std::cout << "아무 키나 눌러주세요...";
        std::cin.get();
        goBack();
        return false;
    }
    return true;
}

bool SignupView::isPasswordMismatch() const {
    return !password.empty() && !confirmPassword.empty() && password != confirmPassword;
}

bool SignupView::registerUser() {
    return userCtrl->addUser(id, password);
} 