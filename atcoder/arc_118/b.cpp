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

typedef pair<int64_t, int64_t> II;

vector<int64_t> solve(int64_t K, int64_t N, int64_t M, std::vector<int64_t> A) {
    priority_queue<II, vector<II>> q;
    vector<int64_t> v(K), r(K);
    for (int i = 0; i < K; i++) {
        v[i] = (A[i] * M) / N;
        r[i] = A[i] * M - v[i] * N;
        q.emplace(II(r[i], i));
    }
    int64_t RM = M - accumulate(v.begin(), v.end(), 0LL);
    for (int j = 0; j < RM; ++j) {
        II top = q.top();
        q.pop();
        int64_t i = top.second;
        v[i] += 1;
        r[i] = A[i] * M - v[i] * N;
        q.emplace(II(r[i], i));
    }
    return v;
}

int main() {
    int64_t K, N, M;
    cin >> K >> N >> M;
    std::vector<int64_t> A(K);
    for (int i = 0; i < K; i++) {
        std::cin >> A[i];
    }
    vector<int64_t> ans = solve(K, N, M, A);
    for (int i = 0; i < K; ++i) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
