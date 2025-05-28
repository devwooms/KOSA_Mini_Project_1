#ifndef STOCK_H
#define STOCK_H

#include <string>
#include "../product/product.h"

using namespace std;

class Stock {
private:
    Product product;
    int quantity;
    string expirationDate;
    
    // CSV 파일 관련 상수
    static const string FILENAME;
    static const string FOLDER_PATH;
    static const string KEYWORD;

public:
    Stock();
    Stock(Product product, int quantity, string expirationDate);

    // get
    int getQuantity() const;
    string getExpirationDate() const;
    const Product& getProduct() const;  // Product 객체 접근자 추가

    // set
    void setQuantity(int qty);
    void setExpirationDate(const string& ed);

    // CSV 파일 관련 메서드
    string getFilename() const { return FILENAME; }
    string getFolderPath() const { return FOLDER_PATH; }
    string getKeyword() const { return KEYWORD; }

    // 제품 정보 출력
    void info() const;
    string toString() const;
    string toCSV() const;
    bool parseFromCSV(const vector<string>& data);
};

#endif
