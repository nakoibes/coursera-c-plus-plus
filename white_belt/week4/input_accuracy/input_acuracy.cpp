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


int main() {
    ifstream input("input.txt");
    //    ofstream output("output.txt");
    double line;
    if (input.is_open()) {
        while (input >> line) {
            cout << fixed << setprecision(3);
            cout << line << endl;
        }
    }
    return 0;
}
