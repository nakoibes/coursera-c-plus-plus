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


class SortedStrings {
public:
    void AddString(const string& s) {
        strings.push_back(s);
        sort(begin(strings), end(strings));
        // добавить строку s в набор
    }
    vector<string> GetSortedStrings() {
        return strings;
        // получить набор из всех добавленных строк в отсортированном порядке
    }
private:
    vector<string> strings;
    // приватные поля
};
void PrintSortedStrings(SortedStrings& s)
{
    for (auto& c:s.GetSortedStrings())
    {
        cout << c << " ";
    }
    cout << endl;

}

int main() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);
    return 0;
}
