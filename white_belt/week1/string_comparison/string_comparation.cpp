//
// Created by nakoibes on 31.07.2021.
//
#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<string> words;
    string a,b,c;
    cin >> a >> b >> c;
    words.push_back(a);
    words.push_back(b);
    words.push_back(c);
    sort(words.begin(),words.end());
    cout << words[0];


    return 0;
}

