//
// Created by Tooster on 30.05.2018.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include "manipulators.hpp"
#include <fstream>
#include <algorithm>

using namespace std;

vector<pair<string, int>> V;

void read(int line, string (*f)(istringstream &iss)) {
    istringstream iss(V[line - 1].first);
    V[line - 1].first = f(iss);
}

int main() {
    fstream file("test.txt", ios_base::in);
    if (!file.is_open())
        return EXIT_FAILURE;

    int lineNumber = 1;
    string line;
    while (getline(file, line))
        V.emplace_back(make_pair(line, lineNumber++));

    read(1, [](istringstream &iss) -> string {
        string a, b, c;
        iss >> a >> b >> ttr::clearline, c;
        return a + b + c;
    });
    read(2, [](istringstream &iss) -> string {
        string a, b, c;
        iss >> a >> b >> ttr::ignore(3) >> c;
        return a + b + c;
    });
    read(5, [](istringstream &iss) -> string {
        string a, b;
        iss >> a >> b;
    });

    sort(V.begin(), V.end());
    for (auto l: V) cout << l.second << ttr::colon << l.first << endl;

    cout << ttr::index(12, 0) << ttr::index(12, 5) << endl;

    file.close();
    return EXIT_SUCCESS;
}