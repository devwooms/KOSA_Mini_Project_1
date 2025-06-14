#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>

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
    string productType;  // instantMeal, drink, tobacco 등 제품 타입 구분

public:
    Product();
    Product(int id, string name, int price, string type);
    virtual ~Product() = default;  // 가상 소멸자 추가

    // CSV 관련 getter
    virtual string getFilename() const { return FILENAME; }
    virtual string getFolderPath() const { return FOLDER_PATH; }
    virtual string getKeyword() const { return KEYWORD; }

    // get
    int getPkId() const;
    string getName() const;
    int getPrice() const;
    string getProductType() const;
    
    // set
    void setPkId(int id);
    void setName(const string& name);
    void setPrice(int price);
    void setProductType(const string& type);

    // 제품 정보 출력
    virtual void info() const;
    virtual string toString() const;

    // CSV 관련 메서드
    virtual string toCSV() const;  // 기본 제품 정보만 CSV로 변환
    virtual string getAdditionalCSV() const { return ""; }  // 자식 클래스의 추가 정보를 toCSV에 추가
    virtual bool parseFromCSV(const vector<string>& data);
    virtual bool parseAdditionalCSV(const vector<string>& data) { return true; }
};

#endif