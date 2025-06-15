#ifndef INVENTORY_MANAGEMENT_VIEW_H
#define INVENTORY_MANAGEMENT_VIEW_H

#include "../baseScreenView.h"
#include "../../controller/screenController.h"
#include <memory>
#include <iostream>
#include <limits>

class inventoryManagementView : public baseScreenView {
public:
    inventoryManagementView();
    void initialize() override;
    void display() override;
};

#endif // INVENTORY_MANAGEMENT_VIEW_H 