#ifndef PRODUCT_MANAGEMENT_VIEW_H
#define PRODUCT_MANAGEMENT_VIEW_H

#include "../BaseScreenView.h"

class ProductManagementView : public BaseScreenView
{
   private:
    int getUserChoice();  // 사용자 입력 처리

   public:
    ProductManagementView();
    void run() override;  // 자체 실행 로직
};

#endif  // PRODUCT_MANAGEMENT_VIEW_H