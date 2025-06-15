#ifndef INVENTORY_LIST_VIEW_H
#define INVENTORY_LIST_VIEW_H

#include "../BaseScreenView.h"

class AdminInventoryListView : public BaseScreenView
{
   private:
   public:
    AdminInventoryListView();
    void run() override;  // 자체 실행 로직
};

#endif  // INVENTORY_LIST_VIEW_H