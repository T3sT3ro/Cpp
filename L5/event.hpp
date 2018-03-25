//
// Created by Tooster on 25.03.2018.
//

#ifndef CPP_EVENT_H
#define CPP_EVENT_H


#include "dateHour.hpp"

class Event {
    DateHour time;
    std::string description;
public:
    Event(const DateHour &time, const std::string &description);

    const DateHour &getTime() const;

    void setTime(const DateHour &time);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    bool operator<(const Event &rhs) const;
};


#endif //CPP_EVENT_H
