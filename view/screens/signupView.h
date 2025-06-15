#ifndef SIGNUP_VIEW_H
#define SIGNUP_VIEW_H

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <memory>

#include "../../controller/UserController.h"
#include "../BaseScreenView.h"

class SignupView : public BaseScreenView
{
   private:
    std::string id;
    std::string password;
    std::string confirmPassword;

   public:
    SignupView();
    void run() override;
};

#endif  // SIGNUP_VIEW_H