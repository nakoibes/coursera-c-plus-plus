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


string FindNameByYear(const map<int, string> &names, int year) {
    string name;

    for (const auto &item : names) {
        if (item.first <= year) {
            name = item.second;
        } else {
            break;
        }
    }

    return name;
}

pair<string, vector<string>> History(const map<int, string> &names, int year) {
    string name;
    vector<string> hist;
    string last_item = "";
    for (const auto &item : names) {
        if (item.first <= year) {
            if (last_item != item.second) {
                hist.push_back(item.second);
                last_item = item.second;
            }
            name = item.second;
        } else {
            break;
        }
    }

    return {name, hist};
}

class Person {
public:
    void ChangeFirstName(int year, const string &first_name) {
        first_names[year] = first_name;
    }

    void ChangeLastName(int year, const string &last_name) {
        last_names[year] = last_name;
    }

    string GetFullName(int year) {
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);

        if (first_name.empty() && last_name.empty()) {
            return "Incognito";

        } else if (first_name.empty()) {
            return last_name + " with unknown first name";

        } else if (last_name.empty()) {
            return first_name + " with unknown last name";

        } else {
            return first_name + " " + last_name;
        }
    }

    string GetFullNameWithHistory(int year) {
        pair<string, vector<string>> first_name_pair = History(first_names, year);
        pair<string, vector<string>> last_name_pair = History(last_names, year);
        reverse(first_name_pair.second.begin(), first_name_pair.second.end());
        reverse(last_name_pair.second.begin(), last_name_pair.second.end());
        if (first_name_pair.first.empty() && last_name_pair.first.empty()) {
            return "Incognito";
        }
        string answer;
        if (!first_name_pair.first.empty()) {
            answer = first_name_pair.first + " ";
            if (first_name_pair.second.size() > 1) {
                answer += "(";
                for (int i = 1; i < first_name_pair.second.size(); ++i) {
                    answer += (first_name_pair.second[i] + ", ");
                }
                answer[answer.size() - 2] = ')';
            }
        }
        if (!last_name_pair.first.empty()) {
            answer += last_name_pair.first;
            if (last_name_pair.second.size() > 1) {
                answer += " (";
                for (int i = 1; i < last_name_pair.second.size(); ++i) {
                    answer += (last_name_pair.second[i] + ", ");

                }
                answer[answer.size() - 2] = ')';
                answer.erase(answer.size() - 1);
            }
        }
        if (first_name_pair.first.empty()) {
            answer += " with unknown first name";
        }
        if (last_name_pair.first.empty()) {
            answer += "with unknown last name";
        }
        return answer;
    }

private:
    map<int, string> first_names;
    map<int, string> last_names;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}
