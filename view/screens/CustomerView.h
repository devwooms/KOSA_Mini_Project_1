#ifndef CUSTOMER_VIEW_H
#define CUSTOMER_VIEW_H

#include "../BaseScreenView.h"

class CustomerView : public BaseScreenView
{
   private:
    int getUserChoice();  // 사용자 입력 처리

   public:
    CustomerView();
    void run() override;  // 자체 실행 로직
};

#endif  // CUSTOMER_VIEW_H