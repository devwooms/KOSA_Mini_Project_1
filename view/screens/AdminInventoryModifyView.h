#ifndef INVENTORY_MODIFY_VIEW_H
#define INVENTORY_MODIFY_VIEW_H

#include "../BaseScreenView.h"

class AdminInventoryModifyView : public BaseScreenView
{
   public:
    AdminInventoryModifyView();
    void run() override;  // 자체 실행 로직
};

#endif  // INVENTORY_MODIFY_VIEW_H