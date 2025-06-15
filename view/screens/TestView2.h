#ifndef TEST_VIEW_2_HPP
#define TEST_VIEW_2_HPP

#include "../baseScreenView.h"
#include "../../controller/screenController.h"
#include <memory>

class TestView2 : public baseScreenView {
public:
    TestView2();
    void initialize();
    void display() override;
};

#endif // TEST_VIEW_2_HPP 