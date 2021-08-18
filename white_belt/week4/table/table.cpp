//
// Created by nakoibes on 13.08.2021.
//

//
// Created by nakoibes on 11.08.2021.
//
#include<iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <fstream>
#include <iomanip>

using namespace std;


int main() {
    int m, n;
    ifstream input("input.txt");
    //    ofstream output("output.txt");
    string line;
    int value;
    if (input.is_open()) {
        input >> n >> m;
        input.ignore(1);
        for (int i = 0;i < n;++i)
        {
            for (int j = 0;j < m-1;++j)
            {
                //                input >> value;
                getline(input,line,',');
                cout << setw(10) << line << ' ';
            }
            getline(input,line);
            cout << setw(10) << line;
            //            input.ignore(1);
            cout << endl;
        }
        //        while (getline(input,line)) {
        //            cout << fixed << setprecision(3);
        //            cout << line << endl;
        //
        //        }
    }
    return 0;
}
