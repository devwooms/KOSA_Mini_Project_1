#include "productController.h"  
#include "../model/entity/product/drink.h"
#include "../model/entity/product/instantMeal.h"
#include "../model/entity/product/tobacoo.h"
#include <sstream>
#include <fstream>

ProductController::ProductController() {
    initializeAttributeSetters();
}

void ProductController::initializeAttributeSetters() {
    attributeSetters["DRINK"] = [](shared_ptr<Product>& product, const map<string, string>& attrs) {
        auto drink = dynamic_pointer_cast<Drink>(product);
        if (drink && attrs.count("isCarbonated")) {
            drink->setIsCarbonated(attrs.at("isCarbonated") == "1");
        }
    };

    attributeSetters["INSTANT_MEAL"] = [](shared_ptr<Product>& product, const map<string, string>& attrs) {
        auto meal = dynamic_pointer_cast<InstantMeal>(product);
        if (meal && attrs.count("isFrozen")) {
            meal->setIsFrozen(attrs.at("isFrozen") == "1");
        }
    };

    attributeSetters["TOBACCO"] = [](shared_ptr<Product>& product, const map<string, string>& attrs) {
        auto tobacco = dynamic_pointer_cast<Tobacco>(product);
        if (tobacco && attrs.count("brand")) {
            tobacco->setBrand(attrs.at("brand"));
        }
    };
}

shared_ptr<Product> ProductController::createProduct(int pkId, const string& name, int price, const string& type, const map<string, string>& attributes) {
    return shared_ptr<Product>(ProductFactory::createProduct(pkId, name, price, type, attributes).release());
}

vector<shared_ptr<Product>> ProductController::getAll() {
    vector<shared_ptr<Product>> result;
    Product defaultProduct;
    vector<string> lines = productCsvRepository.getAllLines(defaultProduct);
    
    for (const auto& line : lines) {
        vector<string> data = productCsvRepository.parseLine(line);
        if (data.size() < 4) continue;

        shared_ptr<Product> product;
        string type = data[3];

        if (type == "DRINK") {
            auto drink = make_shared<Drink>();
            if (drink->parseFromCSV(data)) {
                product = drink;
            }
        } else if (type == "INSTANT_MEAL") {
            auto meal = make_shared<InstantMeal>();
            if (meal->parseFromCSV(data)) {
                product = meal;
            }
        } else if (type == "TOBACCO") {
            auto tobacco = make_shared<Tobacco>();
            if (tobacco->parseFromCSV(data)) {
                product = tobacco;
            }
        }

        if (product) {
            result.push_back(product);
        }
    }
    return result;
}

void ProductController::add(shared_ptr<Product>& product) {
    if (product) {
        string csvLine = product->toCSV();
        if (productCsvRepository.addLine(*product, csvLine)) {
            cout << "데이터가 성공적으로 추가되었습니다." << endl;
        }
    }
}

void ProductController::update(shared_ptr<Product>& product) {
    if (!product) return;

    auto allProducts = getAll();
    bool found = false;

    for (auto& item : allProducts) {
        if (item->getPkId() == product->getPkId()) {
            if (auto drink = dynamic_pointer_cast<Drink>(product)) {
                item = make_shared<Drink>(*drink);
            } else if (auto meal = dynamic_pointer_cast<InstantMeal>(product)) {
                item = make_shared<InstantMeal>(*meal);
            } else if (auto tobacco = dynamic_pointer_cast<Tobacco>(product)) {
                item = make_shared<Tobacco>(*tobacco);
            } else {
                item = make_shared<Product>(*product);
            }
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "업데이트할 제품을 찾지 못했습니다. ID: " << product->getPkId() << endl;
        return;
    }

    vector<string> updatedLines;
    for (const auto& item : allProducts) {
        updatedLines.push_back(item->toCSV());
    }

    if (productCsvRepository.updateLines(*product, updatedLines)) {
        cout << "데이터가 성공적으로 업데이트되었습니다." << endl;
    }
}

void ProductController::remove(shared_ptr<Product>& product) {
    if (!product) return;

    auto allProducts = getAll();
    auto it = remove_if(allProducts.begin(), allProducts.end(),
        [&product](const shared_ptr<Product>& item) { 
            return item->getPkId() == product->getPkId(); 
        });

    if (it == allProducts.end()) {
        cout << "삭제할 제품을 찾지 못했습니다. ID: " << product->getPkId() << endl;
        return;
    }

    allProducts.erase(it, allProducts.end());
    
    vector<string> updatedLines;
    for (const auto& item : allProducts) {
        updatedLines.push_back(item->toCSV());
    }

    if (productCsvRepository.updateLines(*product, updatedLines)) {
        cout << "데이터가 성공적으로 삭제되었습니다." << endl;
    }
}

shared_ptr<Product> ProductController::get(int pkId) {
    auto products = getAll();
    for (const auto& product : products) {
        if (product->getPkId() == pkId) {
            return product;
        }
    }
    return nullptr;
}
