#ifndef ADMIN_PRODUCT_ADD_VIEW_H
#define ADMIN_PRODUCT_ADD_VIEW_H

#include "../BaseScreenView.h"

class AdminProductAddView : public BaseScreenView
{
   private:
    int getUserChoice();  // 사용자 입력 처리

   public:
    AdminProductAddView();
    void run() override;  // 자체 실행 로직
};

#endif  // ADMIN_PRODUCT_ADD_VIEW_H