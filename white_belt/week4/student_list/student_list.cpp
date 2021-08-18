//
// Created by nakoibes on 13.08.2021.
//

//
// Created by nakoibes on 11.08.2021.
//
#include<iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <fstream>
#include <iomanip>

using namespace std;


struct Student {
    string first_name;
    string last_name;
    long day;
    long month;
    long year;

};

int main() {
    int n;
    cin >> n;

    vector<Student> students;
    for (int i = 0; i < n; ++i) {
        string first_name;
        string last_name;
        long day;
        long month;
        long year;
        cin >> first_name >> last_name >> day >> month >> year;
        students.push_back({first_name, last_name, day, month, year});
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string command;
        int value;
        //        cin >> value;
        cin >> command >> value;
        if (value > students.size() || value < 1)
        {
            cout << "bad request" << endl;
            continue;
        }
        if (command == "name") {
            cout << students[value-1].first_name << " " << students[value-1].last_name << endl;
        } else if (command == "date") {
            cout << students[value-1].day << "." << students[value-1].month << "." <<  students[value-1].year << endl;
        } else {
            cout << "bad request" << endl;
        }
    }
    return 0;
}
