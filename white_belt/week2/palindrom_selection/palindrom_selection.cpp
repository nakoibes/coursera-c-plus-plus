//
// Created by nakoibes on 04.08.2021.
//

#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool IsPalindrom(string w)
{
    int word_size = w.size();
    for (int i =0;i<word_size/2;i++)
    {
        if (w[i] != w[word_size-i-1])
            return false;
    }
    return true;
}
vector<string> PalindromFilter(vector<string> words,int minLength)
{
    vector<string> result ={};
    for(auto w:words)
    {
        if(IsPalindrom(w) && w.size() >= minLength)
        {
            result.push_back(w);
        }
    }
    return result;
}
int main() {
    int n;
    cout <<  IsPalindrom("asdbdba");

    return 0;
}
