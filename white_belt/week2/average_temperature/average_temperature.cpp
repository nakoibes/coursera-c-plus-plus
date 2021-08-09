//
// Created by nakoibes on 04.08.2021.
//

#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


vector<int> Reversed(const vector<int> &v) {
    vector<int> result;
    int n = v.size();
    for (int i = n - 1; i >= 0; --i) {
        result.push_back(v[i]);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> temps(n);
    for (auto &t:temps) {
        cin >> t;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += temps[i];
    }
    int avg = sum / n;
    //    cout << avg << endl;
    int count = 0;
    for (auto t :temps) {
        if (t > avg) {
            count += 1;
        }
    }
    cout << count << endl;
    for (int i = 0; i < n; ++i) {
        if (temps[i] > avg) {
            cout << i << " ";
        }
    }
    return 0;
}
