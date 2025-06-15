#ifndef PRODUCT_CONTROLLER_H
#define PRODUCT_CONTROLLER_H

#include "../model/Product.h"
#include "../data/CsvRepository.h"
#include <vector>
#include <memory>

class ProductController {
private:
    static const std::string CSV_PATH;
    std::shared_ptr<CsvRepository> csvRepo;
    
public:
    ProductController();
    
};

#endif // PRODUCT_CONTROLLER_H 