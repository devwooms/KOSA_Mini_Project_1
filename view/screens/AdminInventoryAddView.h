#ifndef INVENTORY_ADD_VIEW_H
#define INVENTORY_ADD_VIEW_H

#include "../BaseScreenView.h"

class AdminInventoryAddView : public BaseScreenView
{
   private:
   public:
    AdminInventoryAddView();
    void run() override;  // 자체 실행 로직
};

#endif  // INVENTORY_ADD_VIEW_H