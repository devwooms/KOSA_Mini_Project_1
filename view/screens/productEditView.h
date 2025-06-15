#ifndef PRODUCT_EDIT_VIEW_H
#define PRODUCT_EDIT_VIEW_H

#include "../BaseScreenView.h"

class ProductEditView : public BaseScreenView
{
   private:
    int getUserChoice();  // 사용자 입력 처리

   public:
    ProductEditView();
    void run() override;  // 자체 실행 로직
};

#endif  // PRODUCT_EDIT_VIEW_H