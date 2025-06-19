#ifndef CUSTOMER_SEARCH_VIEW_H
#define CUSTOMER_SEARCH_VIEW_H

#include "../BaseScreenView.h"

class CustomerSearchView : public BaseScreenView
{
   private:
    std::string getUserChoice();  // 사용자 입력 처리

   public:
    CustomerSearchView();
    void run() override;  // 자체 실행 로직
};

#endif  // CUSTOMER_SEARCH_VIEW_H