//
// Created by nakoibes on 04.08.2021.
//

#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


void MoveStrings(vector<string>& source,vector<string>& destination)
{
    for (auto w :source)
    {
        destination.push_back(w);
    }
    source.clear();
}
int main() {
    int a = 4;
    int b = 2;
    cout << b;

    return 0;
}
