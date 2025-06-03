#ifndef DRINK_H
#define DRINK_H

#include "product.h"

class Drink : public Product {
private:
    int isCarbonated;

public:
    Drink();
    Drink(int id, string name, int price, string type, int isCarbonated);
    virtual ~Drink() = default; 

    // get
    int getIsCarbonated() const;

    // set
    void setIsCarbonated(int isCarbonated);

    // override
    void info() const override;
    string toString() const override;

    // csv
    string toCSV() const override;
    string getAdditionalCSV() const override;
    bool parseFromCSV(const vector<string>& data) override;
    bool parseAdditionalCSV(const vector<string>& data) override;
};
#endif
