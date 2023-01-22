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
#include <atcoder/math>

using namespace std;

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

void solve() {
    vector<long long> factors = { 4,9,5,7,11,13,17,19,23 };
    int64_t M = accumulate(factors.begin(), factors.end(), int64_t(0));
    cout << M << endl;
    fflush(stdout);

    vector<long long> seq;
    for (size_t i = 0; i < factors.size(); ++i) {
        int64_t p = factors[i], base = seq.size() + 1;
        for (int64_t j = 0; j < p; ++j) {
            seq.emplace_back(base + ((j + 1) % p));
        }
    }

    for (size_t i = 0; i < seq.size(); ++i) {
        if (i) cout << " ";
        cout << seq[i];
    }
    cout << endl;
    fflush(stdout);

    vector<int> res = get_ints();

    long long base = 0;
    vector<long long> m;
    for (int i = 0; i < factors.size(); ++i) {
        m.emplace_back(res[base] - base - 1);
        base += factors[i];
    }

    pair<long long, long long> ans = atcoder::crt(m, factors);
    cout << ans.first << endl;
    fflush(stdout);
}

int main() {
    solve();
    return 0;
}
