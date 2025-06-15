#ifndef INVENTORY_LIST_VIEW_H
#define INVENTORY_LIST_VIEW_H

#include "../BaseScreenView.h"

class InventoryListView : public BaseScreenView {
private:
    int getUserChoice();  // 사용자 입력 처리

public:
    InventoryListView();
    void run() override;  // 자체 실행 로직
};

#endif // INVENTORY_LIST_VIEW_H 