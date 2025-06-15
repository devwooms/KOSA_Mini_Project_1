#ifndef INVENTORY_MODIFY_VIEW_H
#define INVENTORY_MODIFY_VIEW_H

#include "../BaseScreenView.h"

class InventoryModifyView : public BaseScreenView {
private:
    int getUserChoice();  // 사용자 입력 처리

public:
    InventoryModifyView();
    void run() override;  // 자체 실행 로직
};

#endif // INVENTORY_MODIFY_VIEW_H 