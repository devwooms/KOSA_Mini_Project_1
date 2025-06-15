#ifndef PRODUCT_EDIT_VIEW_H
#define PRODUCT_EDIT_VIEW_H

#include "../BaseScreenView.h"
#include "../../controller/ProductController.h"
#include <memory>
#include <iostream>
#include <iomanip>
#include <algorithm>

class ProductEditView : public BaseScreenView {
private:
    std::shared_ptr<ProductController> prodCtrl;

public:
    ProductEditView();
    void editProduct();
};

#endif // PRODUCT_EDIT_VIEW_H 