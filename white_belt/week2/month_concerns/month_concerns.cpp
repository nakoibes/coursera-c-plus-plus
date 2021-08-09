//
// Created by nakoibes on 05.08.2021.
//

#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void Print(const vector<string> &v) {
    cout << v.size() << " ";
    for (const auto &w:v) {
        cout << w << " ";
    }
    cout << endl;
}

int main() {
    vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int current_month = 0;
    int n, day;
    string command, name;
    cin >> n;
    vector<vector<string>> tasks(months[0]);
    for (int i = 0; i < n; ++i) {
        cin >> command;
        if (command == "ADD") {
            cin >> day >> name;
            tasks[day - 1].push_back(name);
        } else if (command == "DUMP") {
            cin >> day;
            Print(tasks[day - 1]);
        } else if (command == "NEXT") {
            if (months[(current_month + 1) % 12] >= months[current_month % 12]) {
                tasks.resize(months[(current_month + 1) % 12]);
            } else {
                int next = months[(current_month + 1) % 12];
                int prev = months[current_month % 12];
                //                int difference = prev - next;
                for (int j = next; j < prev; ++j) {
                    for (auto &d:tasks[j]) {
                        tasks[next - 1].push_back(d);
                    }
                }
                tasks.resize(months[(current_month + 1) % 12]);
            }
            ++current_month;

        }
    }
    //    vector<vector<string>> tasks(months[current_month]);
    //    cout << months.size();
    return 0;
}
