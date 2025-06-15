#include "SignupView.h"


SignupView::SignupView() {
    setErrorMessages({
        " ",
        "아이디가 이미 존재합니다.",
        "비밀번호가 일치하지 않습니다."
    });
    setTitle("회원가입");
}

void SignupView::run() {
    while (true) {
        // 화면 지우기
        clearScreen();

        // 에러 메시지 표시
        renderErrorMessages(getErrorMessages()[getShowError()]);

        // 타이틀 표시
        renderTitle(getTitle());

        std::cout << "회원가입을 위해 다음 정보를 입력해주세요. (0: 뒤로가기)\n\n";
        std::cout << "아이디: ";
        std::cin >> id;
        if (id == "0") {
            goBack();
            break;
        }
        std::cout << "비밀번호: ";
        std::cin >> password;
        if (password == "0") {
            goBack();
            break;
        }
        std::cout << "비밀번호 확인: ";
        std::cin >> confirmPassword;
        if (confirmPassword == "0") {
            goBack();
            break;
        }

        if (id.empty() || password.empty() || confirmPassword.empty()) {
            setShowError(1);
            continue;
        }

        if (id.length() < 4 || id.length() > 16) {
            setShowError(1);
            continue;
        }

        if (password != confirmPassword) {
            setShowError(2);
            continue;
        }
        break;
    }
}
