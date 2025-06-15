#ifndef INVENTORY_CONTROLLER_H
#define INVENTORY_CONTROLLER_H

#include "../model/Inventory.h"
#include "CsvController.h"
#include <vector>
#include <memory>

class InventoryController {
private:
    std::shared_ptr<CsvController> csvController;
    
public:
    InventoryController();
    
};

#endif // INVENTORY_CONTROLLER_H 