#ifndef PRODUCT_ADD_VIEW_H
#define PRODUCT_ADD_VIEW_H

#include "../BaseScreenView.h"

class ProductAddView : public BaseScreenView {
private:
    int getUserChoice();  // 사용자 입력 처리

public:
    ProductAddView();
    void run() override;  // 자체 실행 로직
};

#endif // PRODUCT_ADD_VIEW_H 