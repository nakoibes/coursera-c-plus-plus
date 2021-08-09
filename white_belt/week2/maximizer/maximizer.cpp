//
// Created by nakoibes on 04.08.2021.
//

#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void UpdateIfGreater(int a,int& b)
{
    if (a > b)
    {
        b= a;
    }
}
int main() {
    int a = 4;
    int b = 2;
    UpdateIfGreater(a, b);
    cout << b;

    return 0;
}
