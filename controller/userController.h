#ifndef USER_CONTROLLER_H
#define USER_CONTROLLER_H

#include "../model/User.h"
#include "CsvController.h"
#include <memory>
#include <string>
#include <vector>

class UserController {
private:
  // 파일 경로
  static const std::string CSV_PATH;

  // 사용자 목록
  std::vector<User> users;

  // CSV 컨트롤러
  std::shared_ptr<CsvController> csvController;

  // 사용자 목록 로드
  void loadUsers();

  // 최대 사용자 ID 찾기
  int findMaxUserId() const;

public:
  UserController();

  // 사용자 추가
  bool addUser(const std::string &userid, const std::string &password);

  // 사용자 존재 여부 확인
  bool isUserIdExists(const std::string &userid) const;

  // 사용자 찾기
  std::shared_ptr<User> findUser(const std::string &userid) const;
};

#endif // USER_CONTROLLER_H