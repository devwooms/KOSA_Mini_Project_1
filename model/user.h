#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    // 사용자 권한 상수 정의
    static const int ADMIN = 0;      // 관리자 권한
    static const int CUSTOMER = 1;   // 고객 권한

private:
    int ID;                     // 사용자 고유 ID (자동 생성)
    std::string userid;         // 사용자가 입력한 아이디
    std::string userpasswd;     // 사용자 비밀번호
    int Permissions;            // 사용자 권한 (0: admin, 1: customer)

public:
    // 생성자
    User();
    User(const std::string& userid, const std::string& userpasswd, int permissions = CUSTOMER);
    
    // Getter 메서드
    int getID() const { return ID; }
    std::string getUserId() const { return userid; }
    std::string getUserPasswd() const { return userpasswd; }
    int getPermissions() const { return Permissions; }
    
    // Setter 메서드
    void setID(int id) { this->ID = id; }
    void setUserId(const std::string& userid) { this->userid = userid; }
    void setUserPasswd(const std::string& passwd) { this->userpasswd = passwd; }
    void setPermissions(int permissions) { this->Permissions = permissions; }
    
    // 정적 ID 생성기
    static int generateID();

private:
    static int nextID;  // 다음 사용자 ID를 추적하기 위한 정적 변수
};

#endif 