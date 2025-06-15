#ifndef PRODUCT_DELETE_VIEW_H
#define PRODUCT_DELETE_VIEW_H

#include "../BaseScreenView.h"
#include "../../controller/ProductController.h"
#include "../../controller/InventoryController.h"
#include <memory>
#include <iostream>
#include <iomanip>
#include <algorithm>

class ProductDeleteView : public BaseScreenView {
private:
    std::shared_ptr<ProductController> prodCtrl;
    std::shared_ptr<InventoryController> invCtrl;

public:
    ProductDeleteView();
    void deleteProduct();
};

#endif // PRODUCT_DELETE_VIEW_H 