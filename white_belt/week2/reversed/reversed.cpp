//
// Created by nakoibes on 04.08.2021.
//

vector<int> Reversed(const vector<int> &v) {
    vector<int> result;
    int n = v.size();
    for (int i = n-1; i >=0; --i) {
        result.push_back(v[i]);
    }
    return result;
}
