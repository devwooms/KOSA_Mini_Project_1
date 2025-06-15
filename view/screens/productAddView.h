#ifndef PRODUCT_ADD_VIEW_H
#define PRODUCT_ADD_VIEW_H

#include "../baseScreenView.h"
#include "../../controller/screenController.h"
#include "../../controller/productController.h"
#include <memory>
#include <iostream>
#include <string>

class productAddView : public baseScreenView {
private:
    std::shared_ptr<productController> prodCtrl;

public:
    productAddView();
    void initialize() override;
    void display() override;
    void addNewProduct();
};

#endif // PRODUCT_ADD_VIEW_H 