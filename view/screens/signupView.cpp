#include "signupView.h"
#include "../viewRender.h"

signupView::signupView() : currentField(0) {
    initialize();
}

void signupView::initialize() {
    setTitle("회원가입");
    resetState();
}

void signupView::resetState() {
    id = "";
    password = "";
    confirmPassword = "";
    currentField = 0;
}

void signupView::display() {
    system("clear");  // 화면 클리어
    
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

void signupView::displayInputField(const std::string& fieldName, bool isPassword) {
    std::cout << fieldName << "을(를) 입력하세요: ";
}

void signupView::processInput(const std::string& input) {
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

bool signupView::validateInput() {
    if (id.empty() || password.empty() || confirmPassword.empty()) {
        return false;
    }
    return password == confirmPassword;
}

bool signupView::isPasswordMismatch() const {
    return !password.empty() && !confirmPassword.empty() && password != confirmPassword;
} 