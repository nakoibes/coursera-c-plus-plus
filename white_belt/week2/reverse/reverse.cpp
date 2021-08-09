//
// Created by nakoibes on 04.08.2021.
//

#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


void Reverse(vector<int>& v)
{
    int tmp;
    for(int i =0;i<v.size()/2;++i)
    {
        tmp = v[i];
        v[i] = v[v.size()-i-1];
        v[v.size()-i-1] = tmp;

    }
}
int main() {
    int a = 4;
    int b = 2;
    cout << b;

    return 0;
}
