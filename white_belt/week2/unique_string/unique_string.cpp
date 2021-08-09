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


int main() {
    int q;
    //    map<vector<string>,int> routes;
    string command, stop;
    cin >> q;
    set<string> words;

    for (int i = 0; i < q; i++) {
        string word;
        cin >> word;
        words.insert(word);
    }
    cout << words.size() << endl;
    return 0;
}
