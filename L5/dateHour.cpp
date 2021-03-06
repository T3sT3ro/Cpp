//
// Created by Tooster on 25.03.2018.
//

#include <ctime>
#include "dateHour.hpp"

DateHour::DateHour() {
    Date d;
    auto now = std::time(nullptr);
    auto time = std::gmtime(&now);
    *this = DateHour(d.getYear(), d.getMonth(), d.getDay(), time->tm_hour, time->tm_min, time->tm_sec);
    validate();
}

DateHour::DateHour(int year, int month = 1, int day = 1, int hours = 0, int minutes = 0, int seconds = 0) :
        Date(year, month, day), hours(hours), minutes(minutes), seconds(seconds) { validate(); }

DateHour::DateHour(const Date other) : Date(other), hours(0), minutes(0), seconds(0) { validate(); }

//----------------------------------------------------------------------------------------------------------------------
int DateHour::getHours() const {
    return hours;
}

int DateHour::getMinutes() const {
    return minutes;
}

int DateHour::getSeconds() const {
    return seconds;
}

long long DateHour::operator-(const DateHour &rhs) {
    return toJulianSeconds(*this) - toJulianSeconds(rhs);
}

bool DateHour::operator==(const DateHour &rhs) const {
    return year == rhs.year &&
           month == rhs.month &&
           day == rhs.day &&
           hours == rhs.hours &&
           minutes == rhs.minutes &&
           seconds == rhs.seconds;
}

bool DateHour::operator<(const DateHour &rhs) const {
    return toJulianDay(*this) < toJulianDay(rhs) ||
           toJulianDay(*this) == toJulianDay(rhs) && (hourToSeconds(*this) < hourToSeconds(rhs));

}

DateHour &DateHour::operator--() {
    if (--seconds == -1) {
        if (--minutes == -1) {
            if (--hours == -1) {
                Date::operator--();
                hours = 23;
            }
            minutes = 59;
        }
        seconds = 59;
    }
    return *this;
}

DateHour DateHour::operator--(int) {
    DateHour tmp(*this);
    --*this;
    return tmp;
}

DateHour &DateHour::operator++() {
    if (++seconds == 60) {
        if (++minutes == 60) {
            if (++hours == 24) {
                Date::operator++();
                hours = 0;
            }
            minutes = 0;
        }
        seconds = 0;
    }
    return *this;
}

DateHour DateHour::operator++(int) {
    DateHour tmp(*this);
    ++*this;
    return tmp;
}

DateHour DateHour::operator+=(int seconds) {
    DateHour tmp(toDateHour(toJulianSeconds(*this) + seconds));
    return *this = tmp;
}

DateHour DateHour::operator-=(int seconds) {
    return operator+=(-seconds);
}

//----------------------------------------------------------------------------------------------------------------------
void DateHour::validate() const {
    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59)
        throw Date::invalid_date_exception();
}

int DateHour::timeDifference(Date d) const {
    return Date::timeDifference(d);
}

int DateHour::hourToSeconds(DateHour d) {
    return d.seconds + d.minutes * 60 + d.hours * 3600;
}

DateHour DateHour::toDateHour(long long julianseconds) {
    //@formatter:off
    long long juliandays = julianseconds / (24LL * 3600LL);
    DateHour tmp = toDate(juliandays);
    julianseconds -= juliandays * (24LL * 3600LL);
    tmp.hours = static_cast<int>(julianseconds / 3600LL);
    julianseconds -= tmp.hours * 3600LL;
    tmp.minutes = static_cast<int>(julianseconds / 60LL);
    julianseconds -= tmp.minutes * 60LL;
    tmp.seconds = static_cast<int>(julianseconds);
    //@formatter:on
    tmp.validate();
    return tmp;
}

long long DateHour::toJulianSeconds(DateHour d) {
    return toJulianDay(*this) * 24LL * 3600LL + d.hours * 3600LL + d.minutes * 60LL + (long long) d.seconds;
}
