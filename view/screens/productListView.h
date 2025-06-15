#ifndef PRODUCT_LIST_VIEW_H
#define PRODUCT_LIST_VIEW_H

#include "../BaseScreenView.h"
#include "../../controller/ProductController.h"
#include <memory>
#include <iostream>
#include <iomanip>
#include <algorithm>

class ProductListView : public BaseScreenView {
private:
    std::shared_ptr<ProductController> prodCtrl;

public:
    ProductListView();
    void showProductList();
};

#endif // PRODUCT_LIST_VIEW_H 