#ifndef ADMIN_PRODUCT_LIST_VIEW_H
#define ADMIN_PRODUCT_LIST_VIEW_H

#include "../BaseScreenView.h"

class AdminProductListView : public BaseScreenView
{
   private:
    int getUserChoice();  // 사용자 입력 처리

   public:
    AdminProductListView();
    void run() override;  // 자체 실행 로직
};

#endif  // ADMIN_PRODUCT_LIST_VIEW_H