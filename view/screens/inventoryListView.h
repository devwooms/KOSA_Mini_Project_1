#ifndef INVENTORY_LIST_VIEW_H
#define INVENTORY_LIST_VIEW_H

#include "../baseScreenView.h"
#include "../../controller/screenController.h"
#include "../../controller/inventoryController.h"
#include "../../controller/productController.h"
#include <memory>
#include <iostream>
#include <iomanip>

class inventoryListView : public baseScreenView {
private:
    std::shared_ptr<inventoryController> invCtrl;
    std::shared_ptr<productController> prodCtrl;

public:
    inventoryListView();
    void initialize() override;
    void display() override;
    void showInventoryList();
};

#endif // INVENTORY_LIST_VIEW_H 