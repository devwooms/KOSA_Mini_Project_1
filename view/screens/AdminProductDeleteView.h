#ifndef ADMIN_PRODUCT_DELETE_VIEW_H
#define ADMIN_PRODUCT_DELETE_VIEW_H

#include "../BaseScreenView.h"

class AdminProductDeleteView : public BaseScreenView
{
   private:
    int getUserChoice();  // 사용자 입력 처리

   public:
    AdminProductDeleteView();
    void run() override;  // 자체 실행 로직
};

#endif  // ADMIN_PRODUCT_DELETE_VIEW_H