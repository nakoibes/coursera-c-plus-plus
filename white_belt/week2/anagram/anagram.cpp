//
// Created by nakoibes on 07.08.2021.
//

#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

void Print(const vector<string> &v) {
    cout << v.size() << " ";
    for (const auto &w:v) {
        cout << w << " ";
    }
    cout << endl;
}
map<char,int> BuildCharCounters(const string& str)
{
    map<char,int> result;
    for (const auto& c:str)
    {
        result[c]++;
    }
    return result;
}

int main() {
    int n;
    string word1,word2;
    cin >> n;
    for (int i = 0;i<n;i++)
    {
        cin >> word1 >> word2;
        if (BuildCharCounters(word1) == BuildCharCounters(word2))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }


    return 0;
}
