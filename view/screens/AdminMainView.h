#ifndef ADMIN_VIEW_H
#define ADMIN_VIEW_H

#include "../BaseScreenView.h"

class AdminMainView : public BaseScreenView
{
   private:
    int getUserChoice();  // 사용자 입력 처리

   public:
    AdminMainView();
    void run() override;
};

#endif  // ADMIN_VIEW_H