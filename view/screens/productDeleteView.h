#ifndef PRODUCT_DELETE_VIEW_H
#define PRODUCT_DELETE_VIEW_H

#include "../BaseScreenView.h"

class ProductDeleteView : public BaseScreenView {
private:
    int getUserChoice();  // 사용자 입력 처리

public:
    ProductDeleteView();
    void run() override;  // 자체 실행 로직
};

#endif // PRODUCT_DELETE_VIEW_H 