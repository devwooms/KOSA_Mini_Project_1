#ifndef PRODUCT_LIST_VIEW_H
#define PRODUCT_LIST_VIEW_H

#include "../baseScreenView.h"
#include "../../controller/screenController.h"
#include "../../controller/productController.h"
#include <memory>
#include <iostream>
#include <iomanip>

class productListView : public baseScreenView {
private:
    std::shared_ptr<productController> prodCtrl;

public:
    productListView();
    void initialize() override;
    void display() override;
    void showProductList();
};

#endif // PRODUCT_LIST_VIEW_H 