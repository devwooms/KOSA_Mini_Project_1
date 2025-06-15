#ifndef USER_CONTROLLER_H
#define USER_CONTROLLER_H

#include <memory>
#include <string>
#include <vector>

#include "BaseController.h"
#include "../model/User.h"

class UserController : public BaseController
{
   private:
    // 파일 경로
    static const std::string CSV_PATH;
    // 사용자 목록
    std::vector<User> users;

    // 사용자 목록 로드 (BaseController의 순수 가상 함수 구현)
    void loadData() override;

    // 최대 사용자 ID 찾기
    int findMaxUserId() const;

protected:
    // BaseController의 순수 가상 함수들 구현
    std::string getFilePath() const override;
    std::vector<std::string> getHeaders() const override;

   public:
    UserController();

    // 사용자 추가
    bool addUser(const std::string& userid, const std::string& password);

    // 사용자 존재 여부 확인
    bool isUserIdExists(const std::string& userid) const;

    // 사용자 찾기
    std::shared_ptr<User> findUser(const std::string& userid) const;
};

#endif  // USER_CONTROLLER_H