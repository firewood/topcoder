#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

class BIT {
    std::vector<long long> bit;
    long long size;
public:
    BIT() { }
    BIT(long long sz) { init(sz); }
    void init(long long sz) {
        bit = std::vector<long long>((size = sz) + 1);
    }
    long long sum(long long i) {
        LL s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    void add(long long i, long long x) {
        while (i <= size) {
            bit[i] += x;
            i += i & -i;
        }
    }
};

LL solve(long long H, long long W, long long M, std::vector<long long> X, std::vector<long long> Y) {
    LL ans = 0;
    BIT bit(W + 1);
    vector<LL> added(W + 1);
    vector<LL> min_height(W, H);
    vector<vector<LL>> blocks(H, vector<LL>(1, W));
    for (LL i = 0; i < M; ++i) {
        min_height[Y[i]] = min(min_height[Y[i]], X[i]);
        blocks[X[i]].emplace_back(Y[i]);
    }
    for (LL i = 0; i < W; ++i) {
        if (i < *min_element(blocks[0].begin(), blocks[0].end())) {
            ans += min_height[i];
        } else {
            bit.add(i + 1, 1);
            added[i] = 1;
        }
    }
    for (LL i = 1; i < min_height[0]; ++i) {
        ans += bit.sum(*min_element(blocks[i].begin(), blocks[i].end()));
        for (auto j : blocks[i]) {
            bit.add(j + 1, !added[j]);
            added[j] = 1;
        }
    }
    return ans;
}

int main() {
#if DEBUG
    freopen("in_2.txt", "r", stdin);
#endif

    long long H, W, M;
    cin >> H >> W >> M;
    std::vector<long long> X(M), Y(M);
    for (int i = 0 ; i < M ; i++) {
        cin >> X[i] >> Y[i];
        --X[i]; --Y[i];
    }
    cout << solve(H, W, M, std::move(X), std::move(Y)) << endl;
	return 0;
}
