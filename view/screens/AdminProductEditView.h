#ifndef ADMIN_PRODUCT_EDIT_VIEW_H
#define ADMIN_PRODUCT_EDIT_VIEW_H

#include "../BaseScreenView.h"

class AdminProductEditView : public BaseScreenView
{
   private:
    int getUserChoice();  // 사용자 입력 처리

   public:
    AdminProductEditView();
    void run() override;  // 자체 실행 로직
};

#endif  // ADMIN_PRODUCT_EDIT_VIEW_H