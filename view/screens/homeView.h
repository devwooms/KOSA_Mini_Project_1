#ifndef HOME_VIEW_H
#define HOME_VIEW_H

#include "../BaseScreenView.h"

class HomeView : public BaseScreenView {
private:
    int getUserChoice();  // 사용자 입력 처리

public:
    HomeView();
    void run() override;  // 자체 실행 로직
};

#endif // HOME_VIEW_H 