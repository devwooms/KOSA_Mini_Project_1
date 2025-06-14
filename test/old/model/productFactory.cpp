#include "productFactory.h"
#include "entity/product/drink.h"
#include "entity/product/instantMeal.h"
#include "entity/product/tobacoo.h"

using namespace std;

unique_ptr<Product> ProductFactory::createProduct(int pkId, const string& name, int price, const string& type, const map<string, string>& attributes) {
    unique_ptr<Product> product;
    
    if (type == "DRINK") {
        auto drink = make_unique<Drink>(pkId, name, price, type, false);
        if (attributes.count("isCarbonated")) {
            drink->setIsCarbonated(attributes.at("isCarbonated") == "1");
        }
        // 일부 표준 라이브러리는 안전성과 명확성을 위해서
        // using namespace std 를 쓰더라도 붙이는 걸 권장한다고 한다
        product = std::move(drink);
    }
    else if (type == "INSTANT_MEAL") {
        auto meal = make_unique<InstantMeal>(pkId, name, price, type, false);
        if (attributes.count("isFrozen")) {
            meal->setIsFrozen(attributes.at("isFrozen") == "1");
        }
        product = std::move(meal);
    }
    else if (type == "TOBACCO") {
        auto tobacco = make_unique<Tobacco>(pkId, name, price, type, "");
        if (attributes.count("brand")) {
            tobacco->setBrand(attributes.at("brand"));
        }
        product = std::move(tobacco);
    }
    else {
        product = make_unique<Product>(pkId, name, price, type);
    }
    
    return product;
}

unique_ptr<Product> ProductFactory::createFromCSV(const vector<string>& data) {
    if (data.size() < 4) return nullptr;

    int pkId = stoi(data[0]);
    string name = data[1];
    int price = stoi(data[2]);
    string type = data[3];

    map<string, string> attributes;
    if (data.size() > 4) {
        if (type == "DRINK") {
            attributes["isCarbonated"] = data[4];
        }
        else if (type == "INSTANT_MEAL") {
            attributes["isFrozen"] = data[4];
        }
        else if (type == "TOBACCO") {
            attributes["brand"] = data[4];
        }
    }

    return createProduct(pkId, name, price, type, attributes);
}

