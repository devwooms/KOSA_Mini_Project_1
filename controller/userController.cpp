#include "UserController.h"

const std::string UserController::CSV_PATH = "../data/user.csv";

UserController::UserController() : BaseController()
{
    // CSV 파일 초기화 후 데이터 로드
    initializeCsvFile();
    loadData();
}

std::string UserController::getFilePath() const
{
    return CSV_PATH;
}

std::vector<std::string> UserController::getHeaders() const
{
    return {"ID", "UserID", "Password", "Permissions"};
}

void UserController::loadData()
{
    users.clear();
    auto lines = csvRepo->readFile(getFilePath());

    for (size_t i = 1; i < lines.size(); ++i)
    {  // 첫 줄은 헤더이므로 건너뜀
        auto record = csvRepo->csvToVector(lines[i]);
        if (record.size() >= 4)
        {
            User user(std::stoi(record[0]), record[1], record[2], std::stoi(record[3]));
            users.push_back(user);
        }
    }
}

int UserController::findMaxUserId() const
{
    int maxId = 0;
    auto lines = csvRepo->readFile(getFilePath());

    for (size_t i = 1; i < lines.size(); ++i)
    {  // 첫 줄은 헤더이므로 건너뜀
        auto record = csvRepo->csvToVector(lines[i]);
        if (!record.empty())
        {
            int currentId = std::stoi(record[0]);
            maxId = std::max(maxId, currentId);
        }
    }
    return maxId;
}

bool UserController::addUser(const std::string& userid, const std::string& password)
{
    // 이미 존재하는 사용자 ID인지 확인
    if (isUserIdExists(userid))
    {
        return false;
    }

    // 새로운 ID 생성 및 사용자 생성
    int newId = findMaxUserId() + 1;
    User newUser(newId, userid, password, User::CUSTOMER);
    users.push_back(newUser);

    // CSV 파일에 추가
    std::vector<std::string> record = {std::to_string(newId), userid, password,
                                       std::to_string(User::CUSTOMER)};

    return csvRepo->appendFile(getFilePath(), csvRepo->vectorToCsv(record));
}

bool UserController::isUserIdExists(const std::string& userid) const
{
    return findUser(userid) != nullptr;
}

std::shared_ptr<User> UserController::findUser(const std::string& userid) const
{
    for (const auto& user : users)
    {
        if (user.getUserId() == userid)
        {
            return std::make_shared<User>(user);
        }
    }
    return nullptr;
}