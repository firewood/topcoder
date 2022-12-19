#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> II;

vector<int> get_ints() {
    vector<int> r;
    string s;
    getline(cin, s);
    stringstream ss(s);
    while (true) {
        string v;
        ss >> v;
        if (v.empty()) {
            break;
        }
        r.push_back(atoi(v.c_str()));
    }
    return r;
}

void solve(int N) {
    vector<II> v;
    map<II, int> m;
    for (int sz = 1; sz <= N; sz *= 2) {
        for (int i = 0; i + sz <= N; ++i) {
            v.emplace_back(i + 1, i + sz);
        }
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); ++i) {
        m[v[i]] = i + 1;
        cout << v[i].first << " " << v[i].second << endl;
    }
    fflush(stdout);
    int Q = get_ints()[0];
    for (int qi = 0; qi < Q; ++qi) {
        vector<int> cmd = get_ints();
        int left = cmd[0], right = cmd[1];
        int sz = 1;
        for (; left + sz - 1 <= right; sz *= 2) {
            ;
        }
        sz /= 2;
        cout << m[II(left, left + sz - 1)] << " " << m[II(right - sz + 1, right)] << endl;
        fflush(stdout);
    }
}

int main() {
    int N = get_ints()[0];
    solve(N);
	return 0;
}
