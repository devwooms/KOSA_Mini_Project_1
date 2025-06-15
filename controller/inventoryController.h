#ifndef INVENTORY_CONTROLLER_H
#define INVENTORY_CONTROLLER_H

#include "../model/Inventory.h"
#include "../data/CsvRepository.h"
#include <vector>
#include <memory>

class InventoryController {
private:
    static const std::string CSV_PATH;
    std::shared_ptr<CsvRepository> csvRepo;
    
public:
    InventoryController();
    
};

#endif // INVENTORY_CONTROLLER_H 