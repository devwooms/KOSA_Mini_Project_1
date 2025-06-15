#include "loginView.h"
#include "../viewRender.h"

loginView::loginView() : currentField(0), userCtrl(std::make_shared<userController>()) {
    initialize();
}

void loginView::initialize() {
    setTitle("로그인");
    resetState();
}

void loginView::resetState() {
    id = "";
    password = "";
    currentField = 0;
}

void loginView::display() {
    system("clear");  // 화면 클리어
    
    // 타이틀 표시
    std::string title = getTitle();
    std::string border(title.length() + 4, '=');
    std::cout << "\n" << border << "\n";
    std::cout << "= " << title << " =\n";
    std::cout << border << "\n\n";

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

void loginView::displayInputField(const std::string& fieldName, bool isPassword) {
    std::cout << fieldName << "을(를) 입력하세요 (0: 뒤로가기): ";
}

void loginView::processInput(const std::string& input) {
    if (input == "0") {
        getController()->goBack();
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

bool loginView::validateInput() {
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