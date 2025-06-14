#include "user.h"

// 정적 멤버 변수 초기화
int User::nextID = 1;

// 기본 생성자
User::User() : ID(generateID()), userid(""), userpasswd(""), Permissions(CUSTOMER) {}

// 매개변수가 있는 생성자
User::User(const std::string& userid, const std::string& userpasswd, int permissions)
    : ID(generateID()), userid(userid), userpasswd(userpasswd), Permissions(permissions) {}

// ID 생성 메서드
int User::generateID() {
    return nextID++;
} 