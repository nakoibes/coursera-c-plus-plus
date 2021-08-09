//
// Created by nakoibes on 08.08.2021.
//
#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

void Print(const map<string, string> &m) {
    if (m.empty()) {
        cout << "There are no countries in the world";
    } else {
        for (const auto &p:m) {
            cout << p.first << "/" << p.second << " ";
        }
    }
    cout << endl;
}

map<char, int> BuildCharCounters(const string &str) {
    map<char, int> result;
    for (const auto &c:str) {
        result[c]++;
    }
    return result;
}

int main() {
    int n;
    map<string, string> result;
    string command;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "CHANGE_CAPITAL") {
            string country, capital;
            cin >> country >> capital;
            if (result.count(country) == 0) {
                cout << "Introduce new country " << country << " with capital " << capital << endl;
                result[country] = capital;
            } else if (result[country] == capital) {
                cout << "Country " << country << " hasn't changed its capital" << endl;
            } else {
                string old_capital = result[country];
                cout << "Country " << country << " has changed its capital from " << old_capital << " to " << capital
                << endl;
                result[country] = capital;
            }

        } else if (command == "RENAME") {
            string old_name, new_name, tmp;
            cin >> old_name >> new_name;

            if (old_name == new_name || result.count(old_name) == 0 ||
            result.count(new_name) != 0) {
                cout << "Incorrect rename, skip" << endl;
            } else {
                tmp = result[old_name];
                result[new_name] = tmp;
                result.erase(old_name);
                cout << "Country " << old_name << " with capital " << tmp << " has been renamed to " << new_name
                << endl;
            }
        } else if (command == "ABOUT") {
            string country;
            cin >> country;
            if (result.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
            } else {

                cout << "Country " << country << " has capital " << result[country] << endl;

            }
        } else if (command == "DUMP") {
            Print(result);
        }

    }


    return 0;
}

