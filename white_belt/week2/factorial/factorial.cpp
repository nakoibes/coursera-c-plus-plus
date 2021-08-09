//
// Created by nakoibes on 03.08.2021.
//
#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int Factorial(int n)
{
    if (n < 2)
    {
        return 1;
    }
    else
    {
        return Factorial(n-1) *n;
    }
}
int main() {
    int n;
    cout <<  Factorial(5);

    return 0;
}

