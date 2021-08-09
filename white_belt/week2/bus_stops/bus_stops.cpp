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
    int n;
    map<string, vector<string>> buses_to_stops, stops_to_buses;
    string command;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "NEW_BUS") {
            string bus;
            int count;
            cin >> bus;
            cin >> count;
            for (int j = 0; j < count; ++j) {
                string stop;
                cin >> stop;
                buses_to_stops[bus].push_back(stop);
                stops_to_buses[stop].push_back(bus);
            }
        } else if (command == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            if (stops_to_buses.count(stop) != 0) {
                vector<string> bus_list = stops_to_buses[stop];
                PrintBusesForStop(bus_list);
            } else {
                cout << "No stop" << endl;
            }

        } else if (command == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            if (buses_to_stops.count(bus) != 0) {
                vector<string> bus_list, stop_list = buses_to_stops[bus];
                for (const auto &stop:stop_list) {
                    cout << "Stop " << stop << ": ";
                    if (stops_to_buses[stop].size() == 1) {
                        cout << "no interchange" << endl;
                    } else {
                        PrintBusesForStop_1(stops_to_buses[stop], bus);
                    }
                }
            } else {
                cout << "No bus" << endl;
            }
        } else if (command == "ALL_BUSES") {
            if (buses_to_stops.empty()) {
                cout << "No buses" << endl;
            } else {
                for (const auto &p:buses_to_stops) {
                    Print_2(p.second, p.first);
                }
            }
        }


    }


    return 0;
}
