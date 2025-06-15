#include "userController.h"
#include <filesystem>
#include <fstream>
#include <sstream>

const std::string userController::CSV_PATH = "../model/data/user.csv";

userController::userController() : csvCtrl(std::make_shared<csvController>(CSV_PATH)) {
    // CSV 파일 초기화 (헤더 추가)
    csvCtrl->initializeWithHeaders({"ID", "UserID", "Password", "Permissions"});
    
    loadUsers();
}

void userController::loadUsers() {
    users.clear();
    auto records = csvCtrl->readAllRecords();
    
    for (size_t i = 1; i < records.size(); ++i) {  // 첫 줄은 헤더이므로 건너뜀
        const auto& record = records[i];
        if (record.size() >= 4) {
            User user(record[1], record[2], std::stoi(record[3]));
            users.push_back(user);
        }
    }
}

int userController::findMaxUserId() const {
    int maxId = 0;
    auto records = csvCtrl->readAllRecords();
    
    for (size_t i = 1; i < records.size(); ++i) {  // 첫 줄은 헤더이므로 건너뜀
        const auto& record = records[i];
        if (!record.empty()) {
            int currentId = std::stoi(record[0]);
            maxId = std::max(maxId, currentId);
        }
    }
    return maxId;
}

bool userController::addUser(const std::string& userid, const std::string& password) {
    // 이미 존재하는 사용자 ID인지 확인
    if (isUserIdExists(userid)) {
        return false;
    }
    
    // 새로운 사용자 생성
    User newUser(userid, password, User::CUSTOMER);
    users.push_back(newUser);
    
    // CSV 파일에 추가
    std::vector<std::string> record = {
        std::to_string(findMaxUserId() + 1),
        userid,
        password,
        std::to_string(User::CUSTOMER)
    };
    
    return csvCtrl->addRecord(record);
}

bool userController::isUserIdExists(const std::string& userid) const {
    return findUser(userid) != nullptr;
}

std::shared_ptr<User> userController::findUser(const std::string& userid) const {
    for (const auto& user : users) {
        if (user.getUserId() == userid) {
            return std::make_shared<User>(user);
        }
    }
    return nullptr;
} 