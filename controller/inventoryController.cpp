#include "InventoryController.h"

const std::string InventoryController::CSV_PATH = "../data/inventory.csv";

InventoryController::InventoryController() : csvRepo(std::make_shared<CsvRepository>()) {
    // CSV 파일 초기화 (헤더 추가)
    if (!csvRepo->checkFile(CSV_PATH)) {
        csvRepo->appendFile(CSV_PATH, csvRepo->vectorToCsv({"ProductID", "Stock"}));
    }
    loadInventories();
}

void InventoryController::loadInventories() {
    inventories.clear();
    auto lines = csvRepo->readFile(CSV_PATH);
    
    for (size_t i = 1; i < lines.size(); ++i) {  // 첫 줄은 헤더이므로 건너뜀
        auto record = csvRepo->csvToVector(lines[i]);
        if (record.size() >= 2) {
            Inventory inventory(record[0], std::stoi(record[1]));
            inventories.push_back(inventory);
        }
    }
}

std::vector<Inventory> InventoryController::getAllInventories() {
    loadInventories();  // 최신 데이터 로드
    return inventories;
}

Inventory* InventoryController::findInventoryByProductID(const std::string& productID) {
    loadInventories();  // 최신 데이터 로드
    for (auto& inventory : inventories) {
        if (inventory.getProductID() == productID) {
            return &inventory;
        }
    }
    return nullptr;
}

bool InventoryController::addInventory(const std::string& productID, int stock) {
    // 이미 존재하는 제품 ID인지 확인
    if (findInventoryByProductID(productID) != nullptr) {
        return false;
    }
    
    // CSV 파일에 추가
    std::vector<std::string> record = {productID, std::to_string(stock)};
    return csvRepo->appendFile(CSV_PATH, csvRepo->vectorToCsv(record));
}

bool InventoryController::updateInventory(const std::string& productID, int stock) {
    auto lines = csvRepo->readFile(CSV_PATH);
    bool found = false;
    
    for (size_t i = 1; i < lines.size(); ++i) {  // 첫 줄은 헤더이므로 건너뜀
        auto record = csvRepo->csvToVector(lines[i]);
        if (record.size() >= 2 && record[0] == productID) {
            record[1] = std::to_string(stock);
            lines[i] = csvRepo->vectorToCsv(record);
            found = true;
            break;
        }
    }
    
    if (found) {
        return csvRepo->writeFile(CSV_PATH, lines);
    }
    return false;
}

int InventoryController::getStock(const std::string& productID) {
    auto* inventory = findInventoryByProductID(productID);
    return inventory ? inventory->getStock() : 0;
}
