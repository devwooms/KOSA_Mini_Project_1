#ifndef PRODUCT_CONTROLLER_H
#define PRODUCT_CONTROLLER_H

#include <memory>
#include <vector>

#include "../data/CsvRepository.h"
#include "../model/Product.h"

class ProductController
{
   private:
    static const std::string CSV_PATH;
    std::shared_ptr<CsvRepository> csvRepo;

   public:
    ProductController();
};

#endif  // PRODUCT_CONTROLLER_H