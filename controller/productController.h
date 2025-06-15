#ifndef PRODUCT_CONTROLLER_H
#define PRODUCT_CONTROLLER_H

#include "../model/Product.h"
#include "CsvController.h"
#include <vector>
#include <memory>

class ProductController {
private:
    std::shared_ptr<CsvController> csvCtrl;
    
public:
    ProductController();
    
    // CRUD operations
    bool addProduct(const Product& prod);
    std::vector<Product> getAllProducts();
    std::shared_ptr<Product> getProductById(int id);
    std::shared_ptr<Product> getProductByName(const std::string& name);
    bool updateProduct(const Product& prod);
    bool deleteProduct(const std::string& productID);
    
    // Utility methods
    int getNextId();
    bool isProductExists(int id);
    bool isProductNameExists(const std::string& name);
    std::vector<Product> getProductsByCategory(const std::string& category);
    
    // Display methods
    void displayAllProducts();
    void displayProduct(const Product& prod);
};

#endif // PRODUCT_CONTROLLER_H 