//
// Created by nakoibes on 09.08.2021.
//

#include<iostream>
#include <algorithm>
#include <vector>
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
    int q,n,number=1;
    map<vector<string>,int> routes;
    string command,stop;
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> n;

        vector<string> route;
        for (int j = 0;j < n;++j)
        {

            cin >> stop;
            route.push_back(stop);
        }
        if (routes.count(route) != 0)
        {
            cout << "Already exists for " << routes[route] << endl;
        }
        else
        {
            routes[route] = number;
            cout << "New bus " << number << endl;
            number++;
        }
    }
    return 0;
}
