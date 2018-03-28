//
// Created by Tooster on 24.03.2018.
//

#ifndef CPP_DATA_H
#define CPP_DATA_H

#include <stdexcept>

class Date {

protected:
    int year;
    int month;
    int day;

    static constexpr int daysInMonths[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                                                {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    static constexpr int daysElapsed[2][13] = {{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
                                               {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}};

public:

    class invalid_date_exception : public std::runtime_error {
    public:
        invalid_date_exception();
    };

    Date();

    Date(int year, int month, int day);

    Date(const Date &) = default; //
    Date &operator=(const Date &) = default;

//----------------------------------------------------------------------------------------------------------------------
    int getYear() const;

    int getMonth() const;

    int getDay() const;

    int operator-(const Date &);

    Date &operator--(); // pre
    Date operator--(int); // post
    Date &operator++(); // pre
    Date operator++(int); // post
    Date &operator+=(int days);

    Date &operator-=(int days);

//----------------------------------------------------------------------------------------------------------------------
private:
    void validate() const;

protected:
    /// @brief Calculates difference in days as this - d;
    virtual int timeDifference(Date) const;

    static inline bool isLeapYear(Date);

    /// https://en.wikipedia.org/wiki/Julian_day
    /// @brief converts to date to julian day
    static long long int toJulianDay(Date);

    /// @brief converts julian day to gregorian calendar date
    static Date toDate(long long int julianDay);
};


#endif //CPP_DATA_H
