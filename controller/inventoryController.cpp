#include "InventoryController.h"

// 인벤토리 데이터 파일 경로
const std::string InventoryController::CSV_PATH = "../data/inventory.csv";

InventoryController::InventoryController() : BaseController()
{
    // CSV 파일 초기화 후 데이터 로드
    initializeCsvFile();
    loadData();
}

std::string InventoryController::getFilePath() const { return CSV_PATH; }

std::vector<std::string> InventoryController::getHeaders() const { return {"ProductID", "Stock"}; }

void InventoryController::loadData()
{
    inventories.clear();
    auto lines = csvRepo->readFile(getFilePath());

    for (size_t i = 1; i < lines.size(); ++i)
    {  // 첫 줄은 헤더이므로 건너뜀
        auto record = csvRepo->csvToVector(lines[i]);
        if (record.size() >= 2)
        {
            Inventory inventory(record[0], std::stoi(record[1]));
            inventories.push_back(inventory);
        }
    }
}

std::vector<Inventory> InventoryController::getAllInventories()
{
    loadData();  // 최신 데이터 로드
    return inventories;
}

Inventory* InventoryController::findInventoryByProductID(const std::string& productID)
{
    loadData();  // 최신 데이터 로드
    for (auto& inventory : inventories)
    {
        if (inventory.getProductID() == productID)
        {
            return &inventory;
        }
    }
    return nullptr;
}

bool InventoryController::addInventory(const std::string& productID, int stock)
{
    // 이미 존재하는 제품 ID인지 확인
    if (findInventoryByProductID(productID) != nullptr)
    {
        return false;
    }

    // CSV 파일에 추가
    std::vector<std::string> record = {productID, std::to_string(stock)};
    return csvRepo->appendFile(getFilePath(), csvRepo->vectorToCsv(record));
}

bool InventoryController::updateInventory(const std::string& productID, int stock)
{
    auto lines = csvRepo->readFile(getFilePath());
    bool found = false;

    for (size_t i = 1; i < lines.size(); ++i)
    {  // 첫 줄은 헤더이므로 건너뜀
        auto record = csvRepo->csvToVector(lines[i]);
        if (record.size() >= 2 && record[0] == productID)
        {
            record[1] = std::to_string(stock);
            lines[i] = csvRepo->vectorToCsv(record);
            found = true;
            break;
        }
    }

    if (found)
    {
        return csvRepo->writeFile(getFilePath(), lines);
    }
    return false;
}

int InventoryController::getStock(const std::string& productID)
{
    auto* inventory = findInventoryByProductID(productID);
    return inventory ? inventory->getStock() : 0;
}
