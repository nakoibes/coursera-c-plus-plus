//
// Created by nakoibes on 10.08.2021.
//

#include<iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <map>

using namespace std;


bool Comp(string x,string y)
{
    for (auto& c:x)
    {
        c = tolower(c);
    }
    for (auto& c:y)
    {
        c = tolower(c);
    }
    return x < y;
}

int main() {
    int q, number = 1;
    cin >> q;
    vector<string> ar;
    for (int i = 0; i < q; ++i) {
        string str;
        cin >> str;
        ar.push_back(str);
    }
    sort(begin(ar), end(ar), Comp);
    for (const auto &item:ar) {
        cout << item << " ";
    }
    return 0;
}
