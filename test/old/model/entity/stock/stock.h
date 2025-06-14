#ifndef STOCK_H
#define STOCK_H

#include <string>
#include "../product/product.h"

using namespace std;

class Stock {
private:
    // Primary Key
    int pkId;
    string name;
    int price;
    int quantity;
    string expirationDate;
    
    // CSV 파일 관련 상수
    static const string FILENAME;
    static const string FOLDER_PATH;
    static const string KEYWORD;
    static const string HEADER;

public:
    Stock();
    Stock(int pkId, string name, int price, int quantity, string expirationDate);

    // get
    int getPkId() const;
    string getName() const;
    int getPrice() const;
    int getQuantity() const;
    string getExpirationDate() const;

    // set
    void setPkId(int pkId);
    void setName(const string& name);
    void setPrice(int price);
    void setQuantity(int quantity);
    void setExpirationDate(const string& expirationDate);

    

    // CSV 파일 관련 메서드
    string getFilename() const { return FILENAME; }
    string getFolderPath() const { return FOLDER_PATH; }
    string getKeyword() const { return KEYWORD; }
    string getHeader() const { return HEADER; }

    // 제품 정보 출력
    void info() const;
    string toString() const;
    string toCSV() const;
    bool parseFromCSV(const vector<string>& data);
};

#endif
