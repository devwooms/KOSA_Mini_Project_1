#ifndef PRODUCT_CONTROLLER_H
#define PRODUCT_CONTROLLER_H

#include <memory>
#include <vector>

#include "../model/Product.h"
#include "BaseController.h"

class ProductController : public BaseController
{
   private:
    static const std::string CSV_PATH;
    std::vector<Product> products;

    // 제품 목록 로드 (BaseController의 순수 가상 함수 구현)
    void loadData() override;

   protected:
    // BaseController의 순수 가상 함수들 구현
    std::string getFilePath() const override;
    std::vector<std::string> getHeaders() const override;

   public:
    ProductController();

    // 모든 제품 조회
    std::vector<Product> getAllProducts();

    // 특정 제품 ID로 제품 조회
    Product* findProductByProductID(const std::string& productID);

    // 제품 추가
    bool addProduct(const std::string& productID, const std::string& name, int price,
                    const std::string& category, const std::string& description = "");

    // 제품 업데이트
    bool updateProduct(const std::string& productID, const std::string& name, int price,
                       const std::string& category, const std::string& description = "");

    // 제품 삭제
    bool deleteProduct(const std::string& productID);
};

#endif  // PRODUCT_CONTROLLER_H