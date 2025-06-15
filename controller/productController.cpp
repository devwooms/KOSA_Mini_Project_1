#include "ProductController.h"

const std::string ProductController::CSV_PATH = "../data/product.csv";

ProductController::ProductController() : csvRepo(std::make_shared<CsvRepository>()) {
    // CSV 파일 초기화 (헤더 추가)
    if (!csvRepo->checkFile(CSV_PATH)) {
        csvRepo->appendFile(CSV_PATH, csvRepo->vectorToCsv({"ID", "ProductID", "Name", "Price", "Category", "Description"}));
    }
}