#ifndef CONSUMER_VIEW_H
#define CONSUMER_VIEW_H

#include "../baseScreenView.h"
#include "../../controller/screenController.h"
#include <memory>
#include <iostream>
#include <limits>

class consumerView : public baseScreenView {
public:
    consumerView();
    void initialize() override;
    void display() override;
};

#endif // CONSUMER_VIEW_H 