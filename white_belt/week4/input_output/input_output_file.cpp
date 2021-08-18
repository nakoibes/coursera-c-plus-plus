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

using namespace std;


int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    string line;
    if (input.is_open()) {
        while (getline(input, line)) {
            output << line << endl;
        }
    }
    return 0;
}
