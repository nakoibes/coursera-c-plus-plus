//
// Created by nakoibes on 31.07.2021.
//

#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    //    vector<string> words;
    double a, b, c, d, x1, x2;
    cin >> a >> b >> c;
    //    words.push_back(a);
    //    words.push_back(b);
    //    words.push_back(c);
    //    sort(words.begin(),words.end());
    //    cout << words[0];
    if (a == 0) {
        if (b != 0) {
            cout << -c / b;
        }
    } else {

        d = sqrt(b * b - 4 * a * c);
        if (d >= 0) {
            x1 = (-b + d) / (2 * a);
            x2 = (-b - d) / (2 * a);
            if (x1 == x2) {
                cout << x1;
            } else {
                cout << x1 << " " << x2;
            }
        }

    }


    return 0;
}
