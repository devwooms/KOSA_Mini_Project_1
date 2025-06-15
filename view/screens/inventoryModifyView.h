#ifndef INVENTORY_MODIFY_VIEW_H
#define INVENTORY_MODIFY_VIEW_H

#include "../BaseScreenView.h"
#include "../../controller/InventoryController.h"
#include "../../controller/ProductController.h"
#include <memory>
#include <iostream>
#include <iomanip>
#include <algorithm>

class InventoryModifyView : public BaseScreenView {
private:
    std::shared_ptr<InventoryController> invCtrl;
    std::shared_ptr<ProductController> prodCtrl;

public:
    InventoryModifyView();
    void modifyInventory();
};

#endif // INVENTORY_MODIFY_VIEW_H 