#include "validator.h"
#include <regex>
#include <sstream>

using namespace std;

// 날짜 형식 검증
bool Validator::isValidDateFormat(const string& date) {
    // YYYY-MM-DD 형식의 정규식
    // 4자리 숫자 - 01-31 형식의 정규식
    regex datePattern(R"(\d{4}-(?:0[1-9]|1[0-2])-(?:0[1-9]|[12]\d|3[01]))");
    return regex_match(date, datePattern);
}

// 날짜 검증
bool Validator::isValidDate(const string& date) {
    if (!isValidDateFormat(date)) {
        return false;
    }

    stringstream ss(date);
    int year, month, day;
    char delimiter;
    
    ss >> year >> delimiter >> month >> delimiter >> day;
    
    if (year < 1900 || year > 2100) {  // 합리적인 연도 범위 체크
        return false;
    }
    
    return isValidDayInMonth(year, month, day);
}

bool Validator::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Validator::isValidDayInMonth(int year, int month, int day) {
    if (month < 1 || month > 12) {
        return false;
    }

    // 각 월의 일수
    const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // 2월인 경우 윤년 체크
    if (month == 2 && isLeapYear(year)) {
        return day >= 1 && day <= 29;
    }
    
    return day >= 1 && day <= daysInMonth[month];
} 