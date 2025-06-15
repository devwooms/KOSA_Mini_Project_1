#ifndef PRODUCT_DELETE_VIEW_H
#define PRODUCT_DELETE_VIEW_H

#include "../baseScreenView.h"
#include "../../controller/screenController.h"
#include "../../controller/productController.h"
#include "../../controller/inventoryController.h"
#include <memory>
#include <iostream>
#include <string>

class productDeleteView : public baseScreenView {
private:
    std::shared_ptr<productController> prodCtrl;
    std::shared_ptr<inventoryController> invCtrl;

public:
    productDeleteView();
    void initialize() override;
    void display() override;
    void deleteProduct();
};

#endif // PRODUCT_DELETE_VIEW_H 