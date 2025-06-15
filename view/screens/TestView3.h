#ifndef TEST_VIEW_3_HPP
#define TEST_VIEW_3_HPP

#include "../baseScreenView.h"
#include "../../controller/screenController.h"
#include <memory>

class TestView3 : public baseScreenView {
public:
    TestView3();
    void initialize();
    void display() override;
    int getInput() override;
};

#endif // TEST_VIEW_3_HPP 