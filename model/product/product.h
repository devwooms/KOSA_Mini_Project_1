#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

class Product {
private:
    // CSV 정적 변수 선언 (파일 이름, 폴더 경로, 키워드)
    // 메모리 할당 시 한번만 초기화되고 공유되는 변수
    // 메모리 절약 및 효율적인 데이터 관리를 위해 사용
    static const string FILENAME;
    static const string FOLDER_PATH;
    static const string KEYWORD;
    int productId;
    string name;
    string category;
    int price;
    string brand;
    int rewardpoints;
    int expirationDate;
    int wholesalePrice;

public:
    Product();
    Product(int id, string n, string c, int p, string b, int r, int e, int w);

    // CSV 관련 getter
    string getFilename() const { return FILENAME; }
    string getFolderPath() const { return FOLDER_PATH; }
    string getKeyword() const { return KEYWORD; }

    // get
    int getProductId() const;
    string getName() const;
    string getCategory() const;
    int getPrice() const;
    string getBrand() const;
    int getrewardpoints() const;
    int getExpirationDate() const;
    int getWholesalePrice() const;
    
    // set
    void setProductId(int id);
    void setName(const string& n);
    void setCategory(const string& c);
    void setPrice(int p);
    void setBrand(const string& b);
    void setrewardpoints(int s);
    void setExpirationDate(int e);
    void setWholesalePrice(int w);

    // 제품 정보 출력
    void info() const;
    string toString() const;
    string toCSV() const;
};

#endif