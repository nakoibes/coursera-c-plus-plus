//
// Created by nakoibes on 05.08.2021.
//

#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int main() {
    //    int q;
    //    cin >> q;
    //    vector<bool> is_nervous;
    //
    //    for (int i = 0; i < q; ++i) {
    //        string operation_code;
    //        cin >> operation_code;
    //
    //        if (operation_code == "WORRY_COUNT") {
    //
    //            // подсчитываем количество элементов в векторе is_nervous, равных true
    //            cout << count(begin(is_nervous), end(is_nervous), true) << endl;
    //
    //        } else {
    //            if (operation_code == "WORRY" || operation_code == "QUIET") {
    //
    //                int person_index;
    //                cin >> person_index;
    //
    //                // выражение в скобках имеет тип bool и равно true для запроса WORRY,
    //                // поэтому is_nervous[person_index] станет равным false или true
    //                // в зависимости от operation_code
    //                is_nervous[person_index] = (operation_code == "WORRY");
    //
    //            } else if (operation_code == "COME") {
    //
    //                int person_count;
    //                cin >> person_count;
    //
    //                // метод resize может как уменьшать размер вектора, так и увеличивать,
    //                // поэтому специально рассматривать случаи с положительным
    //                // и отрицательным person_count не нужно
    //                is_nervous.resize(is_nervous.size() + person_count, false);
    //
    //            }
    //        }
    //    }
    //
    //    return 0;
    int n;
    cin >> n;
    string command;
    vector<bool> queue;
    for (int i = 0; i < n; ++i) {
        cin >> command;
        if (command == "WORRY_COUNT") {
            cout << count(begin(queue), end(queue), true) << endl;
        } else if (command == "COME") {
            int value;
            cin >> value;
            int new_size = queue.size() + value;
            queue.resize(new_size, false);
        } else if (command == "WORRY" || command == "QUIET") {
            int value;
            cin >> value;
            queue[value] = ("WORRY" == command);
        }
    }
    return 0;
}
