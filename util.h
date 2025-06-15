#ifndef UTIL_H
#define UTIL_H

#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>

namespace util
{
// 입력 버퍼를 비우는 함수
void clearInputBuffer();

// 화면을 완전히 지우고 커서를 처음으로 이동하는 함수
void clearScreen();

// 터미널 유틸리티 함수들
void getTerminalSize(int& rows, int& cols);   // 터미널 크기 얻기
void printCentered(const std::string& text);  // 중앙 정렬 출력
void printNLines(int n);                      // n개의 빈 줄 출력

// 왼쪽에서 시작하는 들여쓰기된 출력
void printLeftAligned(const std::string& text, int indent = 40, bool newline = true);

std::string getInputLine();
void pressEnterToContinue();
void displayError(const std::string& message);
}  // namespace util

#endif  // UTIL_H