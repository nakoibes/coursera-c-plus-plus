//
// Created by nakoibes on 14.08.2021.
//


#include<iostream>
#include <numeric>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>
#include <map>

using namespace std;

void EnsureEqual(const string &left, const string &right) {
    if (left != right) {
        stringstream ss;
        ss << left << " != " << right;
        throw runtime_error(ss.str());
    }
}

int main() {
    try {
        EnsureEqual("C++ White", "C++ White");
        EnsureEqual("C++ White", "C++ Yellow");
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }
    return 0;
}