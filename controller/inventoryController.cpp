#include "InventoryController.h"
    
const std::string InventoryController::CSV_PATH = "../data/inventory.csv";

InventoryController::InventoryController() : csvRepo(std::make_shared<CsvRepository>()) {
    // CSV 파일 초기화 (헤더 추가)
    if (!csvRepo->checkFile(CSV_PATH)) {
        csvRepo->appendFile(CSV_PATH, csvRepo->vectorToCsv({"ProductID", "Stock"}));
    }
}
