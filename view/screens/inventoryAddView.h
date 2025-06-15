#ifndef INVENTORY_ADD_VIEW_H
#define INVENTORY_ADD_VIEW_H

#include "../BaseScreenView.h"

class InventoryAddView : public BaseScreenView {
private:
    int getUserChoice();  // 사용자 입력 처리

public:
    InventoryAddView();
    void run() override;  // 자체 실행 로직
};

#endif // INVENTORY_ADD_VIEW_H 