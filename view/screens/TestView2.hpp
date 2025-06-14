#ifndef TEST_VIEW_2_HPP
#define TEST_VIEW_2_HPP

#include "../baseScreenView.h"
#include <memory>

class TestView2 : public baseScreenView {
public:
    TestView2() { initialize(); }

    void initialize() {
        setTitle("테스트 화면 2");
        // 메뉴 항목 설정
        setMenuItems({
            "테스트 화면 1로 이동",
            "테스트 화면 3으로 이동"
        });

    }







};

#endif // TEST_VIEW_2_HPP 