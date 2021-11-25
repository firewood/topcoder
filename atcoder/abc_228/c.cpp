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

void solve(int64_t N, int64_t K, std::vector<std::vector<int64_t>> P) {
    map<int, vector<int>> m;
    for (int i = 0; i < N; ++i) {
        int sum = 0;
        for (int j = 0; j < 3; ++j) {
            sum += P[i][j];
        }
        m[sum].emplace_back(i);
    }
    vector<int> ans(N), num(1501);
    int cnt = 0;
    for (auto it = m.rbegin(); it != m.rend(); ++it) {
        if (num[it->first + 301] < K) {
            for (auto x : it->second) {
                ans[x] = 1;
            }
        }

        cnt += it->second.size();
        for (int i = 0; i <= it->first; ++i) {
            num[i] = cnt;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << (ans[i] ? "Yes" : "No") << endl;
    }
}

int main() {
#if DEBUG || _DEBUG
    freopen("in_2.txt", "r", stdin);
    //	freopen("in_1.txt", "r", stdin);
#endif
    int64_t N, K;
    std::cin >> N >> K;
    std::vector<std::vector<int64_t>> P(N, std::vector<int64_t>(3));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> P[i][j];
        }
    }
    solve(N, K, P);
    return 0;
}
