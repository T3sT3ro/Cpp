//
// Created by Tooster on 24.03.2018.
//

#include <ctime>
#include <cmath>
#include "date.hpp"

Date::invalid_date_exception::invalid_date_exception() : runtime_error("invalid date.") {}

Date::Date() {
    auto now = std::time(nullptr);
    auto time = std::gmtime(&now);
    year = time->tm_year + 1900;
    month = time->tm_mon + 1;
    day = time->tm_mday;
}

Date::Date(int year, int month, int day) : year(year), month(month), day(day) { validate(); }

//----------------------------------------------------------------------------------------------------------------------
int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

int Date::operator-(const Date &rhs) {
    return this->timeDifference(rhs);
}

Date &Date::operator--() {
    if (--day == 0) {
        if (--month == 0) {
            --year;
            validate();
            month = 12;
        }
        day = daysInMonths[isLeapYear(*this)][month];
    }
    return *this;
}

Date Date::operator--(int) {
    Date tmp(*this);
    operator--();
    return tmp; // old value
}

Date &Date::operator++() {
    if (++day == daysInMonths[isLeapYear(*this)][month]) {
        if (++month == 13) {
            ++year;
            validate();
            month = 1;
        }
        day = 1;
    }
    return *this;
}

Date Date::operator++(int) {
    Date tmp(*this);
    operator++();
    return tmp; // old value
}

Date &Date::operator+=(int days) {
    *this = toDate(toJulianDay(*this) + days);
    return *this;
}

Date &Date::operator-=(int days) {
    return *this += -(days);
}

//----------------------------------------------------------------------------------------------------------------------
void Date::validate() const {
    if ((year < 1582) || (year == 1582 && month < 10) || (year == 1582 && month == 10 && day < 15) // before begin
        || (month > 12) || (day > daysInMonths[isLeapYear(*this)][month]) // numbers too big
        || (month < 1) || (day < 0)) // numbers too small
        throw invalid_date_exception(); // begin of calendar
}

int Date::timeDifference(Date d) const {
    return d.year * 365 + d.year / 4 - d.year / 100 + d.year / 400 - isLeapYear(d) +
           daysElapsed[isLeapYear(d)][d.month - 1] + d.day
           - year * 365 - year / 4 + year / 100 - year / 400 + isLeapYear(*this) -
           daysElapsed[isLeapYear(*this)][month - 1] - day;
}

bool Date::isLeapYear(const Date date) {
    return date.year % 400 == 0 || (date.year % 4 == 0 && date.year % 100 != 0);
}

long long int Date::toJulianDay(const Date d) {
    return (1461 * (d.year + 4800 + (d.month - 14) / 12)) / 4 +
           (367 * (d.month - 2 - 12 * ((d.month - 14) / 12))) / 12 -
           (3 * ((d.year + 4900 + (d.month - 14) / 12) / 100)) / 4 + d.day - 32075;
}

Date Date::toDate(long long int julianDay) {
    Date tmp;
    long long f = julianDay + 1401 + (((4 * julianDay + 274277) / 146097) * 3) / 4 - 38;
    long long e = 4 * f + 3;
    long long g = ((e + 1461) % 1461) / 4;
    long long h = 5 * g + 2;
    tmp.day = static_cast<int>(((h + 153) % 153) / 5 + 1);
    tmp.month = static_cast<int>((h / 153 + 2) % 12 + 1);
    tmp.year = static_cast<int>((e / 1461) - 4716 + (12 + 2 - tmp.month) / 12);
    tmp.validate();
    return tmp;
}
