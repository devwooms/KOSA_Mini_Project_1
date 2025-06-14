#include "util.hpp"

namespace Util {
    void clearBuffer() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void clearScreen() {
        // ANSI 이스케이프 코드를 사용하여 화면을 지우고 커서를 처음으로 이동
        std::cout << "\033[2J";      // 전체 화면 지우기
        std::cout << "\033[3J";      // 스크롤 버퍼 지우기
        std::cout << "\033[H";       // 커서를 처음 위치로 이동
        std::cout.flush();           // 버퍼 즉시 출력
    }
}
