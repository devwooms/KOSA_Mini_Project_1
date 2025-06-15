#include "LoginView.h"


LoginView::LoginView() : currentField(0), userCtrl(std::make_shared<UserController>()) {
    setTitle("로그인");
    resetState();
}

void LoginView::resetState() {
    id = "";
    password = "";
    currentField = 0;
}

void LoginView::display() {
    clearScreen();
    renderTitle(getTitle());
    renderMenuItems(getMenuItems());

    std::cout << "로그인을 위해 다음 정보를 입력해주세요.\n\n";
    
    // 현재까지 입력된 정보 표시
    if (!id.empty()) {
        std::cout << "아이디: " << id << "\n";
    }
    if (!password.empty()) {
        std::cout << "비밀번호: " << std::string(password.length(), '*') << "\n";
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
    }
}

void LoginView::displayInputField(const std::string& fieldName, bool isPassword) {
    std::cout << fieldName << "을(를) 입력하세요 (0: 뒤로가기): ";
}

void LoginView::processInput(const std::string& input) {
    if (input == "0") {
        goBack();
        return;
    }

    switch (currentField) {
        case 0:
            id = input;
            break;
        case 1:
            password = input;
            break;
    }
    currentField++;
}

bool LoginView::validateInput() {
    if (id.empty() || password.empty()) {
        return false;
    }

    auto user = userCtrl->findUser(id);
    if (!user || !user->checkPassword(password)) {
        std::cout << "\n아이디 또는 비밀번호가 일치하지 않습니다!\n";
        std::cout << "아무 키나 눌러주세요...";
        std::cin.get();
        resetState();
        return false;
    }

    currentUser = user;  // 로그인 성공 시 현재 사용자 저장
    return true;
} 