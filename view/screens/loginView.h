#ifndef LOGIN_VIEW_H
#define LOGIN_VIEW_H

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <memory>

#include "../../controller/UserController.h"
#include "../BaseScreenView.h"
#include "AdminMainView.h"
#include "CustomerView.h"

class LoginView : public BaseScreenView
{
   private:
    std::string id;
    std::string password;

   public:
    LoginView();
    void run() override;
};

#endif  // LOGIN_VIEW_H