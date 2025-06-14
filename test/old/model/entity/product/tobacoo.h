#ifndef TOBACCO_H
#define TOBACCO_H

#include "product.h"

class Tobacco : public Product {
private:
    string brand;
public:
    Tobacco();
    Tobacco(int id, string name, int price, string type, string brand);
    virtual ~Tobacco() = default;

    // get
    string getBrand() const;

    // set
    void setBrand(const string& brand);

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