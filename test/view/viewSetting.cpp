#include "viewSetting.h"

using namespace std;

ViewSetting::ViewSetting(const string& title, ViewSetting* parent)
    : title(title), parent(parent) {}

void ViewSetting::clearScreen() const {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void ViewSetting::displayTitle() const {
    string line(title.size() + 4, '-');
    cout << "\033[1;34m"; // 파란색 시작
    cout << "┌" << line << "┐" << endl;
    cout << "│  " << title << "  │" << endl;
    cout << "└" << line << "┘" << endl;
    cout << "\033[0m"; // 색상 리셋
}

void ViewSetting::displayMenu() const {
    cout << "\n=== 메뉴 ===\n";
    
    // 서브메뉴 표시
    for (size_t i = 0; i < subMenus.size(); ++i) {
        cout << i + 1 << ". " << subMenus[i]->title << endl;
    }
    
    // 메뉴 아이템 표시
    for (size_t i = 0; i < menuItems.size(); ++i) {
        cout << i + subMenus.size() + 1 << ". " << menuItems[i].first << endl;
    }
    
    // 뒤로가기 옵션 (루트 메뉴가 아닌 경우에만)
    if (parent) {
        cout << "0. 뒤로 가기" << endl;
    } else {
        cout << "0. 종료" << endl;
    }
    
    cout << "\n선택: ";
}

void ViewSetting::handleInput() {
    int choice;
    cin >> choice;
    
    // 입력 버퍼 클리어
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    if (choice == 0) {
        if (parent) {
            return; // 부모 메뉴로 돌아가기
        } else {
            exit(0); // 프로그램 종료
        }
    }
    
    // 서브메뉴 선택
    if (choice <= static_cast<int>(subMenus.size())) {
        subMenus[choice - 1]->run();
        return;
    }
    
    // 메뉴 아이템 선택
    choice -= subMenus.size();
    if (choice <= static_cast<int>(menuItems.size())) {
        menuItems[choice - 1].second(); // 메뉴 아이템 액션 실행
    } else {
        cout << "\n잘못된 선택입니다. 아무 키나 누르세요...";
        cin.get();
    }
}

void ViewSetting::addMenuItem(const string& label, function<void()> action) {
    menuItems.push_back(make_pair(label, action));
}

void ViewSetting::addSubMenu(const string& label, shared_ptr<ViewSetting> subMenu) {
    subMenus.push_back(subMenu);
}

void ViewSetting::run() {
    while (true) {
        clearScreen();
        displayTitle();
        displayMenu();
        handleInput();
        
        if (parent) {
            // 서브메뉴인 경우, 한 번의 실행 후 부모 메뉴로 돌아감
            return;
        }
    }
}

ViewSetting* ViewSetting::getParent() const {
    return parent;
}
