#include "BaseController.h"

BaseController::BaseController() : csvRepo(std::make_shared<CsvRepository>())
{
    // 순수 가상 함수 호출을 피하기 위해 초기화는 파생 클래스에서 수행
}

bool BaseController::initializeCsvFile()
{
    // 파일이 존재하지 않으면 헤더와 함께 생성
    if (!checkFileExists())
    {
        auto headers = getHeaders();
        return csvRepo->appendFile(getFilePath(), csvRepo->vectorToCsv(headers));
    }
    return true;
}

bool BaseController::checkFileExists() const { return csvRepo->checkFile(getFilePath()); }