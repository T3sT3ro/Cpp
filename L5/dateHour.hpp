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

    DateHour(Date);

    DateHour(const DateHour &) = default; //
    DateHour &operator=(const DateHour &) = default;

//----------------------------------------------------------------------------------------------------------------------
    int getHours() const;

    int getMinutes() const;

    int getSeconds() const;

    bool operator==(const DateHour &) const;

    bool operator<(const DateHour &) const;

    long long operator-(const DateHour &);

    DateHour &operator--(); // pre
    DateHour operator--(int); // post
    DateHour &operator++(); // pre
    DateHour operator++(int); // post
    DateHour operator+=(int seconds);

    DateHour operator-=(int seconds);

//----------------------------------------------------------------------------------------------------------------------
private:

    void validate() const;

protected:
    int timeDifference(Date) const override;

    static inline int hourToSeconds(DateHour);

    static DateHour toDateHour(long long julianseconds);

    long long toJulianSeconds(DateHour);


};


#endif //CPP_DATEHOUR_HPP
