#ifndef INVENTORY_MANAGEMENT_VIEW_H
#define INVENTORY_MANAGEMENT_VIEW_H

#include "../BaseScreenView.h"

class AdminInventoryManagementView : public BaseScreenView
{
   private:
    int getUserChoice();  // 사용자 입력 처리

   public:
    AdminInventoryManagementView();
    void run() override;  // 자체 실행 로직
};

#endif  // INVENTORY_MANAGEMENT_VIEW_H