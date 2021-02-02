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

typedef long long LL;

static const LL INF = 1LL << 60;

LL solve(LL x, LL y) {
    vector<LL> r = {0, -1};
    vector<LL> m = {x, y};
    LL z = atcoder::crt(r, m).first;
    return z ? z : INF;
}

LL solve(long long N) {
    LL ans = INF, N2 = N * 2;
    for (LL i = 1; i * i <= N2; ++i) {
        LL j = N2 / i;
        if (i * j == N2) {
            ans = min(ans, solve(i, j));
            ans = min(ans, solve(j, i));
        }
    }
    return ans;
}

int main() {
    long long N;
    std::cin >> N;
    cout << solve(N) << endl;
    return 0;
}
