#ifndef PRODUCT_ADD_VIEW_H
#define PRODUCT_ADD_VIEW_H

#include "../BaseScreenView.h"
#include "../../controller/ProductController.h"
#include <memory>
#include <iostream>
#include <iomanip>
#include <algorithm>

class ProductAddView : public BaseScreenView {
private:
    std::shared_ptr<ProductController> prodCtrl;

public:
    ProductAddView();
    void addNewProduct();
};

#endif // PRODUCT_ADD_VIEW_H 