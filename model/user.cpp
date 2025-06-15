#include "User.h"

// 기본 생성자
User::User() : ID(0), userid(""), userpasswd(""), Permissions(CUSTOMER) {}

// 매개변수가 있는 생성자
User::User(int id, const std::string& userid, const std::string& userpasswd, int permissions)
    : ID(id), userid(userid), userpasswd(userpasswd), Permissions(permissions) {} 