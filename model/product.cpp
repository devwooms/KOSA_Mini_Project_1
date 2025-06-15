#include "Product.h"

// 기본 생성자
Product::Product() : id(0), productID(""), name(""), price(0), category(""), description("") {}

// 매개변수가 있는 생성자
Product::Product(int id, const std::string& productID, const std::string& name, int price,
                 const std::string& category, const std::string& description)
    : id(id),
      productID(productID),
      name(name),
      price(price),
      category(category),
      description(description)
{
}