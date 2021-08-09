//
// Created by nakoibes on 01.08.2021.
//

#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    while (true) {
        if (a > b && a%b != 0) {
            a = a%b;
        }
        else if (a < b && b %a !=0)
        {
            b = b% a;
        }
        else
        {
            break;
        }
    }
    if (a < b)
    {
        cout << a;
    }
    else cout << b;
    //    cout << a << ' ' <<b;
    return 0;
}
