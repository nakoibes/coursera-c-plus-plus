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
    int q;
    cin >> q;
    map<string, set<string>> dict;
    for (int i = 0; i < q; i++) {
        string command;
        cin >> command;
        if (command == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            dict[word1].insert(word2);
            dict[word2].insert(word1);
        } else if (command == "COUNT") {
            string word;
            cin >> word;
            if (dict.count(word) != 0) {
                cout << dict[word].size() << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (command == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;
            if (dict[word1].count(word2) == 0)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}
