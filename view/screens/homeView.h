#ifndef HOME_VIEW_H
#define HOME_VIEW_H

#include "../baseScreenView.h"
#include "../../controller/screenController.h"
#include <memory>
#include <iostream>
#include <limits>

class homeView : public baseScreenView {
public:
    homeView();
    void initialize();
    void display() override;
};

#endif // HOME_VIEW_H 