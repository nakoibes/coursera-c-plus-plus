//
// Created by nakoibes on 31.07.2021.
//

#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    if (b == 0)
    {
        cout << "Impossible";
    }
    else
    {
        cout << a/b;
    }

    return 0;
}
