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
#include <atcoder/modint>

using namespace std;

using mint = atcoder::modint;

typedef pair<int64_t, int64_t> II;

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> A) {
    vector<vector<int64_t>> t(N, vector<int64_t>(N, -1));

    int64_t mi = -1, mj = -1, mx = -1;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            mint x, y, z;
            x.set_mod(M);
            y.set_mod(M);
            z.set_mod(M);
            x = A[i];
            y = A[j];
            z = x.pow(A[j]) + y.pow(A[i]);
            t[i][j] = t[j][i] = z.val();
            if (t[i][j] > mx) {
                mx = t[i][j];
                mi = i;
                mj = j;
            }
        }
    }

    int64_t ans = t[mi][mj];
    vector<int> u(N);
    int cnt = 2;
    priority_queue<II> q;
    auto enq = [&](int x) {
        u[x] = 1;
        for (int i = 0; i < N; ++i) {
            if (!u[i] && t[x][i] >= 0) {
                q.emplace(t[x][i], i);
            }
        }
    };
    enq(mi);
    enq(mj);
    while (!q.empty()) {
        int64_t c = q.top().first, k = q.top().second;
        q.pop();
        if (u[k]) continue;
        ans += c;
        ++cnt;
        enq(k);
    }
    return ans;
}

int main() {
    int64_t N, M;
    std::cin >> N >> M;
    std::vector<int64_t> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    cout << solve(N, M, A) << endl;
    return 0;
}
