#include "LoginView.h"

LoginView::LoginView() {
    setErrorMessages({
        " ",
        "아이디 또는 비밀번호가 일치하지 않습니다.",
        "로그인이 완료되었습니다!"
    });
    setTitle("로그인");
}

void LoginView::run() {
    UserController userController;
    setShowError(0);
    while (true) {
        // 화면 지우기
        clearScreen();

        // 에러 메시지 표시
        renderErrorMessages(getErrorMessages()[getShowError()]);

        // 타이틀 표시
        renderTitle(getTitle());

        std::cout << "로그인을 위해 다음 정보를 입력해주세요. (0: 뒤로가기)\n\n";
        
        // 아이디 입력
        std::cout << "아이디: ";
        std::cin >> id;
        if (id == "0") {
            goBack();
            break;
        }
        
        // 비밀번호 입력
        std::cout << "비밀번호: ";
        std::cin >> password;
        if (password == "0") {
            goBack();
            break;
        }
        
        // 로그인 검증
        auto user = userController.findUser(id);
        if (!user || user->getUserPasswd() != password) {
            setShowError(1); // "아이디 또는 비밀번호가 일치하지 않습니다."
            continue;
        }
        
        // 로그인 성공
        setShowError(2); // "로그인이 완료되었습니다!"
        
        // 성공 화면 표시
        clearScreen();
        renderErrorMessages(getErrorMessages()[getShowError()]);
        renderTitle(getTitle());
        
        std::cout << "환영합니다, " << user->getUserId() << "님!\n";
        std::cout << "권한: ";
        switch (user->getPermissions()) {
            case User::ADMIN:
                std::cout << "관리자";
                break;
            case User::CUSTOMER:
                std::cout << "고객";
                break;
            default:
                std::cout << "알 수 없음";
                break;
        }
        std::cout << "\n\n";
        std::cout << "계속하려면 Enter를 누르세요...";
        std::cin.ignore();
        std::cin.get();

        switch (user->getPermissions()) {
            case User::CUSTOMER:
                goToScreenSkip(std::make_shared<CustomerView>());
                break;
            case User::ADMIN:
                goToScreenSkip(std::make_shared<AdminView>());
                break;
            default:
                goBack();
                break;
        }
        break;
    }
} 