#ifndef ADMIN_VIEW_H
#define ADMIN_VIEW_H

#include "../baseScreenView.h"
#include "../../controller/screenController.h"
#include <memory>
#include <iostream>
#include <limits>

class adminView : public baseScreenView {
public:
    adminView();
    void initialize() override;
    void display() override;
};

#endif // ADMIN_VIEW_H 