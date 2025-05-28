#ifndef PRODUCT_MANAGER_H
#define PRODUCT_MANAGER_H

#include "../model/product/product.h"

using namespace std;

class ProductManager {
    public:
        ProductManager();
        ~ProductManager();

        void addProduct(const Product& product);
        void removeProduct(const string& name);
        void updateProduct(const string& name, const Product& newProduct);
        void displayAllProducts() const;
        void searchProduct(const string& name) const;
};
#endif