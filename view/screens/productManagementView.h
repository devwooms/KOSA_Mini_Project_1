#ifndef PRODUCT_MANAGEMENT_VIEW_H
#define PRODUCT_MANAGEMENT_VIEW_H

#include "../baseScreenView.h"
#include "../../controller/screenController.h"
#include <memory>
#include <iostream>
#include <limits>

class productManagementView : public baseScreenView {
public:
    productManagementView();
    void initialize() override;
    void display() override;
};

#endif // PRODUCT_MANAGEMENT_VIEW_H 