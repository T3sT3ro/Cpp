//
// Created by Tooster on 25.03.2018.
//

#ifndef CPP_DATEHOUR_HPP
#define CPP_DATEHOUR_HPP


#include "date.hpp"

class DateHour final : public Date {
protected:
    int hours;
    int minutes;
    int seconds;
public:

    DateHour();

    DateHour(int year, int month, int day, int hours, int minutes, int seconds);

    DateHour(Date date);

    DateHour(const DateHour &other) = default;

    DateHour &operator=(const DateHour &other) = default;

//----------------------------------------------------------------------------------------------------------------------
    int getHours() const;

    int getMinutes() const;

    int getSeconds() const;

    bool operator==(const DateHour &rhs) const;

    bool operator<(const DateHour &rhs) const;

    virtual long long operator-(const DateHour &rhs);

    DateHour &operator--(); // pre
    DateHour operator--(int); // post
    DateHour &operator++(); // pre
    DateHour operator++(int); // post
    DateHour operator+=(int seconds);

    DateHour operator-=(int seconds);

//----------------------------------------------------------------------------------------------------------------------
protected:

    void validate() const override;

    int timeDifference(Date d) const override;

    static inline int hourToSeconds(DateHour d);

    static DateHour toDateHour(long long julianseconds);

    long long toJulianSeconds(DateHour d);


};


#endif //CPP_DATEHOUR_HPP
