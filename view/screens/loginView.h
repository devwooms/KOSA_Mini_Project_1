#ifndef LOGIN_VIEW_H
#define LOGIN_VIEW_H

#include "../../controller/UserController.h"
#include "../BaseScreenView.h"
#include "CustomerView.h"
#include "AdminView.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <memory>

class LoginView : public BaseScreenView {
private:
  std::string id;
  std::string password;

public:
  LoginView();
  void run() override;
};

#endif // LOGIN_VIEW_H 