#include "SignupView.h"

SignupView::SignupView() {
    setErrorMessages({
        " ",
        "아이디가 이미 존재합니다.",
        "비밀번호가 일치하지 않습니다.",
        "회원가입이 완료되었습니다!"
    });
    setTitle("회원가입");
}

void SignupView::run() {
    UserController userController;
    int errorType = 0;
    
    while (true) {
        // 화면 지우기
        clearScreen();

        // 에러 메시지 표시
        renderErrorMessages(getErrorMessages()[errorType]);

        // 타이틀 표시
        renderTitle(getTitle());

        std::cout << "회원가입을 위해 다음 정보를 입력해주세요. (0: 뒤로가기)\n\n";
        
        // 아이디 입력
        std::cout << "아이디: ";
        std::cin >> id;
        if (id == "0") {
            goBack();
            break;
        }
        
        // 아이디 중복 검사
        if (userController.isUserIdExists(id)) {
            errorType = 1; // "아이디가 이미 존재합니다."
            continue;
        }
        
        // 비밀번호 입력
        std::cout << "비밀번호: ";
        std::cin >> password;
        if (password == "0") {
            goBack();
            break;
        }
        
        // 비밀번호 확인 입력
        std::cout << "비밀번호 확인: ";
        std::cin >> confirmPassword;
        if (confirmPassword == "0") {
            goBack();
            break;
        }
        
        // 비밀번호 일치 검사
        if (password != confirmPassword) {
            errorType = 2; // "비밀번호가 일치하지 않습니다."
            continue;
        }
        
        // 회원가입 처리
        if (userController.addUser(id, password)) {
            // 성공 메시지 표시
            errorType = 3; // "회원가입이 완료되었습니다!"
            
            // 성공 화면 표시
            clearScreen();
            renderErrorMessages(getErrorMessages()[errorType]);
            renderTitle(getTitle());
            
            std::cout << "아이디: " << id << "\n";
            std::cout << "회원가입이 성공적으로 완료되었습니다!\n\n";
            std::cout << "계속하려면 Enter를 누르세요...";
            std::cin.ignore();
            std::cin.get();
            
            goBack(); // 이전 화면으로 돌아가기
            break;
        } else {
            // 회원가입 실패 (예상치 못한 오류)
            errorType = 1; // 기본 에러 메시지
            continue;
        }
    }
}
