#include "util.hpp"
#include <iostream>
#include <limits>

using namespace std;

namespace Util {
    // 입력 버퍼를 지우는 함수
    void clearBuffer() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // 화면을 완전히 지우고 커서를 처음으로 이동하는 함수
    void clearScreen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    // 터미널 크기 얻기
    void getTerminalSize(int& rows, int& cols) {
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        rows = w.ws_row;
        cols = w.ws_col;
    }

    // 중앙 정렬 출력
    void printCentered(const string& text) {
        int rows, cols;
        getTerminalSize(rows, cols);
        int padding = (cols - text.length()) / 2;
        if (padding > 0) {
            cout << string(padding, ' ') << text << endl;
        } else {
            cout << text << endl;
        }
    }

    // n개의 빈 줄 출력
    void printNLines(int n) {
        for (int i = 0; i < n; i++) {
            cout << endl;
        }
    }

    // 왼쪽에서 시작하는 들여쓰기된 출력
    void printLeftAligned(const string& text, int indent, bool newline) {
        cout << string(indent, ' ') << text;
        if (newline) cout << endl;
    }
}
