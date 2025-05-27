#include <iostream>
#include "../csv/csvManager.cpp"

int main(){
    std::cout << "My Test" << std::endl;

    CsvManager csvManager;
    csvManager.checkDirectory("test");
    csvManager.checkFile("test/test.csv");

    return 0;
}