//
// Created by nakoibes on 01.08.2021.
//

#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> result;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            result.push_back(1);
            //            result.insert(result,0,1);
            //            result.in(0,1);
            n /=2;
        }
        else
        {
            result.push_back(0);
            n/=2;
        }
    }
    //    swap(result);
    for (int x = result.size() - 1;x> -1;--x)
    {
        cout << result[x];
    }

    return 0;
}
