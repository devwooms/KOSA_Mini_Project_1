#ifndef PRODUCT_CONTROLLER_H
#define PRODUCT_CONTROLLER_H

#include "../model/product.h"
#include "csvController.h"
#include <vector>
#include <memory>

class productController {
private:
    std::shared_ptr<csvController> csvCtrl;
    
public:
    productController();
    
    // CRUD operations
    bool addProduct(const product& prod);
    std::vector<product> getAllProducts();
    std::shared_ptr<product> getProductById(int id);
    std::shared_ptr<product> getProductByName(const std::string& name);
    bool updateProduct(const product& prod);
    bool deleteProduct(const std::string& productID);
    
    // Utility methods
    int getNextId();
    bool isProductExists(int id);
    bool isProductNameExists(const std::string& name);
    std::vector<product> getProductsByCategory(const std::string& category);
    
    // Display methods
    void displayAllProducts();
    void displayProduct(const product& prod);
};

#endif // PRODUCT_CONTROLLER_H 