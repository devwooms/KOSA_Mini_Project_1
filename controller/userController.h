#ifndef USER_CONTROLLER_H
#define USER_CONTROLLER_H

#include "../model/User.h"
#include "CsvController.h"
#include <memory>
#include <string>
#include <vector>

class UserController {
private:
  static const std::string CSV_PATH;
  std::shared_ptr<CsvController> csvCtrl;
  std::vector<User> users;

  void loadUsers();
  int findMaxUserId() const;

public:
  UserController();
  bool addUser(const std::string &userid, const std::string &password);
  bool isUserIdExists(const std::string &userid) const;
  std::shared_ptr<User> findUser(const std::string &userid) const;
};

#endif // USER_CONTROLLER_H