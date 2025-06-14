#ifndef TEST_VIEW_1_HPP
#define TEST_VIEW_1_HPP

#include "../baseScreenView.h"
#include <memory>

class TestView1 : public baseScreenView {
public:
    TestView1() { initialize(); }

    void initialize() {
        setTitle("테스트 화면 1");
        // 메뉴 항목 설정
        setMenuItems({
            "테스트 화면 2로 이동",
            "테스트 화면 3으로 이동"
        });

    }


};

#endif // TEST_VIEW_1_HPP 