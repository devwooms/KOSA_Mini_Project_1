#include "Inventory.h"

Inventory::Inventory() : productID(""), stock(0) {}

Inventory::Inventory(const std::string& productID, int stock) : productID(productID), stock(stock)
{
}
