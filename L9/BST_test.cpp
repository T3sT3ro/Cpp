//
// Created by i300791 on 23.05.18.
//

#include "BST.hpp"

#include <iostream>

using namespace structs;
using namespace std;

int main() {

    BST<int> B;

    string op = "";
    string helpmsg = "[x]-close [?]-help [i _]-insert [r _]-remove [m]-min [s]-size [p]-print\n";
    cout << helpmsg;
    while(op != "x"){
        cin >> op;
        if(op == "x") break;
        if(op == "h") cout << helpmsg;
        if(op == "i"){
            int d; cin >> d;
            B.insert(d);
        }
        if(op == "r"){
            int d; cin >> d;
            B.remove(d);
        }
        if(op == "m") cout << B.min();
        if(op == "s") cout << B.size();
        if(op == "p") cout << B;
    }

    return 0;
}