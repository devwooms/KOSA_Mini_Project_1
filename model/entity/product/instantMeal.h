#ifndef INSTANT_MEAL_H
#define INSTANT_MEAL_H

#include "product.h"

class InstantMeal : public Product {
private:
    int isFrozen;  // true: 냉동, false: 냉장

public:
    InstantMeal();
    InstantMeal(int id, string name, int price, string type, int isFrozen);
    virtual ~InstantMeal() = default;

    // get
    int getIsFrozen() const;

    // set
    void setIsFrozen(int isFrozen);

    void info() const override;
    string toString() const override;

    // csv
    string toCSV() const override;
    string getAdditionalCSV() const override;
    bool parseFromCSV(const vector<string>& data) override;
    bool parseAdditionalCSV(const vector<string>& data) override;
    
};

#endif