#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <filesystem>
#include "product.cpp"

using namespace std;
using namespace std::filesystem;

class ProductManager {
private:
    string filename;
    string keyword = "products";
    string folderPath = "./products";
    vector<Product> products;

public:
    // ProductManager(const std::string& fname = "products.csv") : filename(fname) {}


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
                    std::string filename = entry.path().filename().string();
                    if (entry.path().extension() == ".csv" && filename.find(keyword) != std::string::npos) {
                        std::cout << "조건에 맞는 CSV 파일: " << filename << '\n';
                        found = true;
                    }
                }
            }

            if (!found) {
                std::cout << "조건에 맞는 CSV 파일이 없습니다.\n";
            }

        } catch (const std::exception& e) {
            std::cerr << "오류: " << e.what() << '\n';
        }

        return found;
    }

    // CSV 파일에 제품 저장
    void saveToCSV() {


        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cout << "파일을 열 수 없습니다." << std::endl;
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
        std::cout << "제품 정보가 CSV 파일에 저장되었습니다." << std::endl;
    }

    // CSV 파일에서 제품 불러오기
    void loadFromCSV() {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "파일을 열 수 없습니다." << std::endl;
            return;
        }

        products.clear();
        std::string line;
        
        // 헤더 건너뛰기
        std::getline(file, line);

        // 제품 정보 읽기
        while (std::getline(file, line)) {
            std::string name, category, brand;
            int price;
            std::istringstream ss(line);
            std::string item;

            // 이름
            std::getline(ss, name, ',');
            // 카테고리
            std::getline(ss, category, ',');
            // 가격
            std::getline(ss, item, ',');
            price = std::stoi(item);
            // 브랜드
            std::getline(ss, brand, ',');

            products.push_back(Product(name, category, price, brand));
        }

        file.close();
        std::cout << "CSV 파일에서 제품 정보를 불러왔습니다." << std::endl;
    }

    // 제품 추가
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    // 모든 제품 표시
    void displayAllProducts() const {
        if (products.empty()) {
            std::cout << "저장된 제품이 없습니다." << std::endl;
            return;
        }

        std::cout << "\n=== 전체 제품 목록 ===" << std::endl;
        for (const auto& product : products) {
            product.displayInfo();
        }
    }

    // 제품 검색
    void searchProduct(const std::string& name) const {
        bool found = false;
        for (const auto& product : products) {
            if (product.getName() == name) {
                product.displayInfo();
                found = true;
            }
        }
        if (!found) {
            std::cout << "해당 제품을 찾을 수 없습니다." << std::endl;
        }
    }

    // 제품 수정
    void updateProduct(const std::string& name, const Product& newProduct) {
        for (auto& product : products) {
            if (product.getName() == name) {
                product = newProduct;
                std::cout << "제품 정보가 수정되었습니다." << std::endl;
                return;
            }
        }
        std::cout << "해당 제품을 찾을 수 없습니다." << std::endl;
    }

    // 제품 삭제
    void deleteProduct(const std::string& name) {
        auto it = std::remove_if(products.begin(), products.end(),
            [&name](const Product& p) { return p.getName() == name; });
        
        if (it != products.end()) {
            products.erase(it, products.end());
            std::cout << "제품이 삭제되었습니다." << std::endl;
        } else {
            std::cout << "해당 제품을 찾을 수 없습니다." << std::endl;
        }
    }
}; 