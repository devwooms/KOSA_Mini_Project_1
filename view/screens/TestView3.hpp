#ifndef TEST_VIEW_3_HPP
#define TEST_VIEW_3_HPP

#include "../baseScreenView.h"
#include <memory>





class TestView3 : public baseScreenView {
public:
    TestView3() { initialize(); }

    void initialize() {
        setTitle("테스트 화면 3");
        // 메뉴 항목 설정
        setMenuItems({
            "테스트 화면 1로 이동",
            "테스트 화면 2로 이동"
        });


    }



};

#endif // TEST_VIEW_3_HPP 