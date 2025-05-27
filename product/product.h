#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

class Product {
private:
    int productId;
    string name;
    string category;
    int price;
    string brand;
    float rewardpoints;
    float expirationDate;
    int wholesalePrice;

public:
    Product();
    Product(int id, string n, string c, int p, string b, float r, float e, int w);

    // get
    int getProductId() const;
    string getName() const;
    string getCategory() const;
    int getPrice() const;
    string getBrand() const;
    float getrewardpoints() const;
    float getExpirationDate() const;
    int getWholesalePrice() const;

    // set
    void setProductId(int id);
    void setName(const string& n);
    void setCategory(const string& c);
    void setPrice(int p);
    void setBrand(const string& b);
    void setrewardpoints(float s);
    void setExpirationDate(float e);
    void setWholesalePrice(int w);

    // 제품 정보 출력
    void info() const;
};

#endif