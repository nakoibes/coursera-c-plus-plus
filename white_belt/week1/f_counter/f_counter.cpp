//
// Created by nakoibes on 01.08.2021.
//

#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    string word;
    cin >> word;
    int counter = 0;
    int index = 0;
    for(int i = 0;i< word.size();++i)
    {
        if (word[i] == 'f')
        {
            counter +=1;
            index = i;
        }
        if (counter == 2)
        {
            break;
        }
    }
    if (counter == 1)
    {
        cout << -1;

    } else if (counter == 0)
    {
        cout << -2;
    }
    else
    {
        cout << index;
    }


    return 0;
}
