#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <filesystem>
#include "../product/product.cpp"


using namespace std;
using namespace filesystem;

class ProductManager {
private:
    string filename;
    string keyword = "products";
    string folderPath = "./products";
    vector<Product> products;

public:
    // ProductManager(const string& fname = "products.csv") : filename(fname) {}


    // 디렉토리 존재 여부 확인
    bool checkDirectory(){
        if (!exists(folderPath)) {
            create_directory(folderPath);
            cout << "products 디렉토리가 생성되었습니다." << endl;
        }
        // 파일 경로 설정
        filename = folderPath + "/products.csv";
    }

    // 파일 존재 여부 확인
    bool checkFile(){
        bool found = false;

        try {
            for (const auto& entry : directory_iterator(folderPath)) {
                if (entry.is_regular_file()) {
                    string filename = entry.path().filename().string();
                    if (entry.path().extension() == ".csv" && filename.find(keyword) != string::npos) {
                        cout << "조건에 맞는 CSV 파일: " << filename << '\n';
                        found = true;
                    }
                }
            }

            if (!found) {
                cout << "조건에 맞는 CSV 파일이 없습니다.\n";
            }

        } catch (const exception& e) {
            cerr << "오류: " << e.what() << '\n';
        }

        return found;
    }

    // CSV 파일에 제품 저장
    void saveToCSV() {


        ofstream file(filename);
        if (!file.is_open()) {
            cout << "파일을 열 수 없습니다." << endl;
            return;
        }

        // 헤더 작성
        file << "이름,카테고리,가격,브랜드\n";

        // 제품 정보 저장
        for (const auto& product : products) {
            file << product.getName() << ","
                 << product.getCategory() << ","
                 << product.getPrice() << ","
                 << product.getBrand() << "\n";
        }

        file.close();
        cout << "제품 정보가 CSV 파일에 저장되었습니다." << endl;
    }

    // CSV 파일에서 제품 불러오기
    void loadFromCSV() {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "파일을 열 수 없습니다." << endl;
            return;
        }

        products.clear();
        string line;
        
        // 헤더 건너뛰기
        getline(file, line);

        // 제품 정보 읽기
        while (getline(file, line)) {
            int productId;
            string name;
            string category;
            string brand;
            int price;
            float rewardpoints;
            float expirationDate;
            int wholesalePrice;
            istringstream ss(line);
            string item;

            // 이름
            getline(ss, name, ',');
            // 카테고리
            getline(ss, category, ',');
            // 가격
            getline(ss, item, ',');
            price = stoi(item);
            // 브랜드
            getline(ss, brand, ',');

            products.push_back(Product(productId, name, category, price, brand, rewardpoints, expirationDate, wholesalePrice));
        }

        file.close();
        cout << "CSV 파일에서 제품 정보를 불러왔습니다." << endl;
    }

    // 제품 추가
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    // 모든 제품 표시
    void displayAllProducts() const {
        if (products.empty()) {
            cout << "저장된 제품이 없습니다." << endl;
            return;
        }

        cout << "\n=== 전체 제품 목록 ===" << endl;
        for (const auto& product : products) {
            product.info();
        }
    }

    // 제품 검색
    void searchProduct(const string& name) const {
        bool found = false;
        for (const auto& product : products) {
            if (product.getName() == name) {
                product.info();
                found = true;
            }
        }
        if (!found) {
            cout << "해당 제품을 찾을 수 없습니다." << endl;
        }
    }

    // 제품 수정
    void updateProduct(const string& name, const Product& newProduct) {
        for (auto& product : products) {
            if (product.getName() == name) {
                product = newProduct;
                cout << "제품 정보가 수정되었습니다." << endl;
                return;
            }
        }
        cout << "해당 제품을 찾을 수 없습니다." << endl;
    }

    // 제품 삭제
    void deleteProduct(const string& name) {
        auto it = remove_if(products.begin(), products.end(),
            [&name](const Product& p) { return p.getName() == name; });
        
        if (it != products.end()) {
            products.erase(it, products.end());
            cout << "제품이 삭제되었습니다." << endl;
        } else {
            cout << "해당 제품을 찾을 수 없습니다." << endl;
        }
    }
}; 