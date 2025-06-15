#ifndef PRODUCT_EDIT_VIEW_H
#define PRODUCT_EDIT_VIEW_H

#include "../baseScreenView.h"
#include "../../controller/screenController.h"
#include "../../controller/productController.h"
#include <memory>
#include <iostream>
#include <string>

class productEditView : public baseScreenView {
private:
    std::shared_ptr<productController> prodCtrl;

public:
    productEditView();
    void initialize() override;
    void display() override;
    void editProduct();
};

#endif // PRODUCT_EDIT_VIEW_H 