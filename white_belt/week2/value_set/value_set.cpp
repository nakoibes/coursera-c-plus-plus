//
// Created by nakoibes on 09.08.2021.
//

#include<iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <map>

using namespace std;

void PrintBusesForStop(const vector<string> &buses) {
    for (const auto &bus:buses) {
        cout << bus << " ";
    }
    cout << endl;
}

void PrintBusesForStop_1(const vector<string> &buses, const string &bus) {

    for (const auto &item:buses) {
        if (item != bus) {
            cout << item << " ";
        }
    }
    cout << endl;

}

void Print_2(const vector<string> &stops, const string &bus) {
    cout << "Bus " << bus << ": ";
    for (const auto &stop:stops) {
        cout << stop << " ";
    }
    cout << endl;
}
set<string> BuildMapValuesSet(const map<int, string>& m)
{
    set<string> result;
    for (const auto& p:m)
    {
        result.insert(p.second);
    }
    return result;
}


//int main() {
//    set<string> values = BuildMapValuesSet({
//        {1, "odd"},
//        {2, "even"},
//        {3, "odd"},
//        {4, "even"},
//        {5, "odd"}
//    });
//
//    for (const string& value : values) {
//        cout << value << endl;
//    }
//    return 0;
//}
