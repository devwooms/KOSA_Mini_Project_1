#ifndef INVENTORY_ADD_VIEW_H
#define INVENTORY_ADD_VIEW_H

#include "../baseScreenView.h"
#include "../../controller/screenController.h"
#include "../../controller/inventoryController.h"
#include "../../controller/productController.h"
#include <memory>
#include <iostream>
#include <string>

class inventoryAddView : public baseScreenView {
private:
    std::shared_ptr<inventoryController> invCtrl;
    std::shared_ptr<productController> prodCtrl;

public:
    inventoryAddView();
    void initialize() override;
    void display() override;
    void addNewInventory();
};

#endif // INVENTORY_ADD_VIEW_H 