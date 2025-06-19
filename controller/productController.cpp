#include "ProductController.h"

#include <algorithm>

const std::string ProductController::CSV_PATH = "../data/product.csv";

ProductController::ProductController() : BaseController()
{
    // CSV 파일 초기화 후 데이터 로드
    initializeCsvFile();
    loadData();
}

std::string ProductController::getFilePath() const { return CSV_PATH; }

std::vector<std::string> ProductController::getHeaders() const
{
    return {"ID", "ProductID", "Name", "Price", "Category", "Description"};
}

void ProductController::loadData()
{
    products.clear();
    auto lines = csvRepo->readFile(getFilePath());

    for (size_t i = 1; i < lines.size(); ++i)
    {  // 첫 줄은 헤더이므로 건너뜸
        auto record = csvRepo->csvToVector(lines[i]);
        if (record.size() >= 6)
        {
            Product product(std::stoi(record[0]), record[1], record[2], std::stoi(record[3]),
                            record[4], record[5]);
            products.push_back(product);
        }
    }
}

std::vector<Product> ProductController::getAllProducts()
{
    loadData();  // 최신 데이터 로드
    return products;
}

Product* ProductController::findProductByProductID(const std::string& productID)
{
    loadData();  // 최신 데이터 로드
    for (auto& product : products)
    {
        if (product.getProductID() == productID)
        {
            return &product;
        }
    }
    return nullptr;
}

std::vector<Product> ProductController::searchProductsByName(const std::string& keyword)
{
    loadData();  // 최신 데이터 로드
    std::vector<Product> matchedProducts;

    for (const auto& product : products)
    {
        // 제품명에 검색어가 포함되어 있는지 확인 (대소문자 구분 없이)
        std::string productName = product.getName();
        std::string lowerKeyword = keyword;
        std::string lowerProductName = productName;

        // 소문자로 변환
        std::transform(lowerKeyword.begin(), lowerKeyword.end(), lowerKeyword.begin(), ::tolower);
        std::transform(lowerProductName.begin(), lowerProductName.end(), lowerProductName.begin(),
                       ::tolower);

        if (lowerProductName.find(lowerKeyword) != std::string::npos)
        {
            matchedProducts.push_back(product);
        }
    }

    return matchedProducts;
}

bool ProductController::addProduct(const std::string& productID, const std::string& name, int price,
                                   const std::string& category, const std::string& description)
{
    // 이미 존재하는 제품 ID인지 확인
    if (findProductByProductID(productID) != nullptr)
    {
        return false;
    }

    // 새로운 ID 생성 (간단히 현재 제품 수 + 1로 설정)
    int newId = static_cast<int>(products.size()) + 1;

    // CSV 파일에 추가
    std::vector<std::string> record = {std::to_string(newId), productID, name,
                                       std::to_string(price), category,  description};
    return csvRepo->appendFile(getFilePath(), csvRepo->vectorToCsv(record));
}

bool ProductController::updateProduct(const std::string& productID, const std::string& name,
                                      int price, const std::string& category,
                                      const std::string& description)
{
    auto lines = csvRepo->readFile(getFilePath());
    bool found = false;

    for (size_t i = 1; i < lines.size(); ++i)
    {  // 첫 줄은 헤더이므로 건너뜀
        auto record = csvRepo->csvToVector(lines[i]);
        if (record.size() >= 6 && record[1] == productID)
        {
            record[2] = name;
            record[3] = std::to_string(price);
            record[4] = category;
            record[5] = description;
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

bool ProductController::deleteProduct(const std::string& productID)
{
    auto lines = csvRepo->readFile(getFilePath());
    std::vector<std::string> newLines;
    bool found = false;

    // 헤더는 그대로 유지
    if (!lines.empty())
    {
        newLines.push_back(lines[0]);
    }

    for (size_t i = 1; i < lines.size(); ++i)
    {  // 첫 줄은 헤더이므로 건너뜀
        auto record = csvRepo->csvToVector(lines[i]);
        if (record.size() >= 6 && record[1] == productID)
        {
            found = true;
            // 해당 라인은 newLines에 추가하지 않음 (삭제)
        }
        else
        {
            newLines.push_back(lines[i]);
        }
    }

    if (found)
    {
        return csvRepo->writeFile(getFilePath(), newLines);
    }
    return false;
}