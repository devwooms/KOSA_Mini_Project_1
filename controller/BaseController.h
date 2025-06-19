#ifndef BASE_CONTROLLER_H
#define BASE_CONTROLLER_H

#include <memory>
#include <string>
#include <vector>

#include "../data/CsvRepository.h"

class BaseController
{
   protected:
    // CSV 리포지토리 - 모든 Controller가 공통으로 사용
    std::shared_ptr<CsvRepository> csvRepo;

    // 순수 가상 함수들 - 각 Controller에서 구현해야 함
    virtual std::string getFilePath() const = 0;
    virtual std::vector<std::string> getHeaders() const = 0;
    virtual void loadData() = 0;

    // 공통 기능들
    bool initializeCsvFile();
    bool checkFileExists() const;

   public:
    // 생성자
    BaseController();

    // 가상 소멸자
    virtual ~BaseController() = default;
};

#endif  // BASE_CONTROLLER_H