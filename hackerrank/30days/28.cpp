#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    map<string, string> m;
    for (int i = 0; i < N; ++i) {
        string a, b;
        cin >> a >> b;
        if (b.find("@gmail.com") != string::npos) {
            m[b] = a;
        }
    }
    vector<string> names;
    for (auto kv : m) {
        names.push_back(kv.second);
    }
    sort(names.begin(), names.end());
    for (auto name : names) {
        cout << name << endl;
    }
    return 0;
}
