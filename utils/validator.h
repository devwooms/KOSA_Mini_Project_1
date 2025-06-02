#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <regex>

class Validator {
public:
    // 날짜 관련 검증
    static bool isValidDateFormat(const std::string& date);
    static bool isValidDate(const std::string& date);
    
    // 향후 다른 정규식 검증 메서드들이 여기에 추가될 수 있음
    // 예: 이메일, 전화번호, 주소 등의 검증

private:
    // 날짜 검증을 위한 메서드
    static bool isLeapYear(int year);
    static bool isValidDayInMonth(int year, int month, int day);
};

#endif 