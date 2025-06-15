#ifndef LOGIN_VIEW_H
#define LOGIN_VIEW_H

#include "../baseScreenView.h"
#include "../../controller/screenController.h"
#include <memory>
#include <iostream>
#include <limits>

class loginView : public baseScreenView {
public:
    loginView();
    void initialize() override;
    void display() override;
};

#endif // LOGIN_VIEW_H 