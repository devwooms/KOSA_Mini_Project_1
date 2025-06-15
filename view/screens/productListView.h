#ifndef PRODUCT_LIST_VIEW_H
#define PRODUCT_LIST_VIEW_H

#include "../BaseScreenView.h"

class ProductListView : public BaseScreenView {
private:
    int getUserChoice();  // 사용자 입력 처리

public:
    ProductListView();
    void run() override;  // 자체 실행 로직
};

#endif // PRODUCT_LIST_VIEW_H 