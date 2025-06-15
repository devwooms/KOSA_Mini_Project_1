#ifndef USER_CONTROLLER_H
#define USER_CONTROLLER_H

#include "../model/user.h"
#include "csvController.h"
#include <string>
#include <vector>
#include <memory>

class userController {
private:
    static const std::string CSV_PATH;
    std::shared_ptr<csvController> csvCtrl;
    std::vector<User> users;

    void loadUsers();
    int findMaxUserId() const;

public:
    userController();
    bool addUser(const std::string& userid, const std::string& password);
    bool isUserIdExists(const std::string& userid) const;
    std::shared_ptr<User> findUser(const std::string& userid) const;
};

#endif // USER_CONTROLLER_H 