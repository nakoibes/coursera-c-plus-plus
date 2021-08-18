//
// Created by nakoibes on 11.08.2021.
//

#include<iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <map>

using namespace std;

class ReversibleString {
public:
    ReversibleString()
    {
        str = "";
    }
    ReversibleString(const string &data) {
        str = data;
    }

    string ToString() const {
        return str;
    }

    void Reverse() {
        reverse(str.begin(), str.end());
    }

private:
    string str;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString &s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}