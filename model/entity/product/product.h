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
    // Primary Key
    int pkId;
    string name;
    int price;

public:
    static string getCSVHeader();
    Product();
    Product(int id, string n, int p);

    // CSV 관련 getter
    virtual string getFilename() const { return FILENAME; }
    virtual string getFolderPath() const { return FOLDER_PATH; }
    virtual string getKeyword() const { return KEYWORD; }

    // get
    int getPkId() const;
    string getName() const;
    int getPrice() const;
    
    // set
    void setPkId(int id);
    void setName(const string& n);
    void setPrice(int p);


    // 제품 정보 출력
    virtual void info() const;
    virtual string toString() const;
    virtual string toCSV() const;
    virtual bool parseFromCSV(const vector<string>& data);
};

#endif