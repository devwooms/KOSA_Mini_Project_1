// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>
// #include <sstream>
// #include <filesystem>

// #include "csvManager.h"
// #include "../model/product/product.h"



// using namespace std;
// using namespace filesystem;

// void CsvManager::checkDirectory(string folderPath){
//     try {
//         if (!exists(folderPath)) {
//             if (create_directory(folderPath)) {
//                 cout << "디렉토리가 생성되었습니다: " << folderPath << endl;
//             } else {
//                 cout << "디렉토리 생성 실패: " << folderPath << endl;
//             }
//         } else {
//             cout << "디렉토리가 이미 존재합니다: " << folderPath << endl;
//         }
//     } catch (const filesystem_error& e) {
//         cout << "오류 발생: " << e.what() << endl;
//     }
// };
// void CsvManager::checkFile(string filename){
//     if (!exists(filename)) {
//         ofstream file(filename);
//         file.close();
//         cout << "파일이 생성되었습니다." << endl;
//     } else {
//         cout << "파일이 이미 존재합니다." << endl;
//     }
// };
// // void CsvManager::saveCSV(Product product){
// //     checkDirectory(product.getFolderPath());
// //     checkFile(product.getFilename());
// //     ofstream file(product.getFilename());
// //     file << product.toString();
// //     file.close();
// // };

// void CsvManager::saveCSV(string filename, string folderPath, string keyword, string data){
//     checkDirectory(folderPath);
//     checkFile(filename);
//     ofstream file(filename);
//     file << data;
//     file.close();
// };
// void CsvManager::updateCSV(){};
// void CsvManager::loadCSV(){};