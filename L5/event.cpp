//
// Created by Tooster on 25.03.2018.
//

#include "event.hpp"

Event::Event(const DateHour &time, const std::string &description) : time(time), description(description) {}

const DateHour &Event::getTime() const {
    return time;
}

void Event::setTime(const DateHour &time) {
    Event::time = time;
}

const std::string &Event::getDescription() const {
    return description;
}

void Event::setDescription(const std::string &description) {
    Event::description = description;
}

bool Event::operator<(const Event &rhs) const {
    return time < rhs.time;
}
