#ifndef INVENTORY_ADD_VIEW_H
#define INVENTORY_ADD_VIEW_H

#include "../BaseScreenView.h"
#include "../../controller/InventoryController.h"
#include "../../controller/ProductController.h"
#include <memory>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

class InventoryAddView : public BaseScreenView {
private:
    std::shared_ptr<InventoryController> invCtrl;
    std::shared_ptr<ProductController> prodCtrl;

public:
    InventoryAddView();
    void addNewInventory();
};

#endif // INVENTORY_ADD_VIEW_H 