#ifndef INVENTORY_LIST_VIEW_H
#define INVENTORY_LIST_VIEW_H

#include "../BaseScreenView.h"
#include "../../controller/InventoryController.h"
#include "../../controller/ProductController.h"
#include <memory>
#include <iostream>
#include <iomanip>
#include <algorithm>

class InventoryListView : public BaseScreenView {
private:
    std::shared_ptr<InventoryController> invCtrl;
    std::shared_ptr<ProductController> prodCtrl;

public:
    InventoryListView();
    void showInventoryList();
};

#endif // INVENTORY_LIST_VIEW_H 