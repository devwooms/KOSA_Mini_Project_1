#ifndef INVENTORY_MODIFY_VIEW_H
#define INVENTORY_MODIFY_VIEW_H

#include "../baseScreenView.h"
#include "../../controller/screenController.h"
#include "../../controller/inventoryController.h"
#include "../../controller/productController.h"
#include <memory>
#include <iostream>
#include <string>

class inventoryModifyView : public baseScreenView {
private:
    std::shared_ptr<inventoryController> invCtrl;
    std::shared_ptr<productController> prodCtrl;

public:
    inventoryModifyView();
    void initialize() override;
    void display() override;
    void modifyInventory();
};

#endif // INVENTORY_MODIFY_VIEW_H 