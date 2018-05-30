//
// Created by Tooster on 30.05.2018.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include "manipulators.hpp"
#include <algorithm>
#include <sstream>

using namespace std;

vector<pair<string, int>> V;

void read(int line, string (*f)(istringstream &iss)) {
    istringstream iss(V[line - 1].first);
    V[line - 1].first = f(iss);
}

int main(int argc, char *argv[]) {
    fstream file("test.txt", ios_base::in);
    if (!file.is_open())
        return EXIT_FAILURE;

    int lineNumber = 1;
    string line;
    while (getline(file, line))
        V.emplace_back(make_pair(line, lineNumber++));

    read(1, [](istringstream &iss) -> string { // clearline
        string a, b, c;
        iss >> a >> b >> streams::clearline, c;
        return a + b + c;
    });

    read(6, [](istringstream &iss) -> string { // clearline eol
        string a, b, c;
        iss >> a >> b >> streams::clearline, c;
        return a + b + c;
    });
    read(2, [](istringstream &iss) -> string { // ignore
        string a, b, c;
        iss >> a >> b >> streams::ignore(3) >> c;
        return a + " " + b + " " + c;
    });
    read(3, [](istringstream &iss) -> string { // ignore eol
        string a, b, c;
        iss >> a >> b >> streams::ignore(3) >> c;
        return a + " " + b + " " + c;
    });
    read(5, [](istringstream &iss) -> string {
        int a, b;
        iss >> a >> b;
        string ret;
        stringstream oss(ret);
        oss << streams::index(a, b) << streams::comma;
        oss >> ret;
        return ret;
    });


    sort(V.begin(), V.end());
    for (auto l: V) cout << streams::index(l.second, 2) << streams::colon << l.first << endl;

    file.close();

    if (argc < 3) {
        cout << "Pass two files for binary streams testing.\n";
        return EXIT_FAILURE;
    }
    try {
        streams::ibfstream ibfs(argv[1]);
        streams::obfstream obfs(argv[2]);
        if (!ibfs || !obfs) return EXIT_FAILURE;
        vector<int> VI;
        for (int i = 0; ibfs.ifs; ++i) {
            int x;
            ibfs >> x;
            VI.push_back(x);
        }
        for (auto x: VI)
            obfs << (x + 1);

    } catch (exception &e) {
        cout << e.what();
        return EXIT_FAILURE;
    }


    return EXIT_SUCCESS;
}