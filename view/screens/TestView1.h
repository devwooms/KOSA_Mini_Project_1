#ifndef TEST_VIEW_1_HPP
#define TEST_VIEW_1_HPP

#include "../baseScreenView.h"
#include "../../controller/screenController.h"
#include <memory>
#include <iostream>
#include <limits>

class TestView1 : public baseScreenView {
public:
    TestView1();
    void initialize();
    void display() override;
    int getInput() override;
};

#endif // TEST_VIEW_1_HPP 