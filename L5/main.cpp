//
// Created by Tooster on 24.03.2018.
//

#include "date.hpp"
#include "event.hpp"
#include <vector>
#include <algorithm>

int main() {
    DateHour d1;
    DateHour d2(d1);
    d2.Date::operator+=(2);
    DateHour d3(d2);
    d3 += 3600;
    std::vector<Event> evts;
    evts.emplace_back(Event(d1, "Pick up grandma from airport."));
    evts.emplace_back(Event(d1 += 7 * 3600, "Realize, she is the mastermind behind global warming."));
    evts.emplace_back(Event(d2, "Buy a shovel."));
    evts.emplace_back(Event(d3, "Bury grandma on a desert."));
    evts.emplace_back(Event(++d3, "Realize you have sinned."));
    evts.emplace_back(Event(d3.Date::operator++(), "People start asking where grandmother is..."));
    auto f = [](Event a, Event b) -> bool { return b < a; };
    auto p = [](Event e) -> void {
        const DateHour &d = e.getTime();
        printf("[%d.%d.%d %02d:%02d:%02d] \t%s\n",
               d.getDay(), d.getMonth(), d.getYear(),
               d.getHours(), d.getMinutes(), d.getSeconds(),
               e.getDescription().c_str());
    };

    std::sort(evts.begin(), evts.end());
    for (auto &e : evts) p(e);
    std::printf("Retrospection from the end:\n");
    std::sort(evts.begin(), evts.end(), f);
    for (auto &e : evts) p(e);
    std::printf("Seconds between shove bought and sin realization: %d\n", (int) (d3 - d2));
    return 0;
}