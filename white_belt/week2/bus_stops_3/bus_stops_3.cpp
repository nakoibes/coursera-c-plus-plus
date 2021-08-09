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

set<string> BuildMapValuesSet(const map<int, string> &m) {
    set<string> result;
    for (const auto &p:m) {
        result.insert(p.second);
    }
    return result;
}


int main() {
    int q, number = 1;
    cin >> q;
    map<set<string>, int> result;
    for (int i = 0; i < q; ++i) {
        int n;
        set<string> stops;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            string stop;
            cin >> stop;
            stops.insert(stop);
        }
        if (result.count(stops) != 0) {
            cout << "Already exists for " << result[stops] << endl;

        } else {
            result[stops] = number;
            cout << "New bus " << number << endl;
            number++;
        }

    }
    return 0;
}
