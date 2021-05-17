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
typedef pair<int64_t, II> III;

int64_t solve(int64_t N, std::vector<int64_t> &D, std::vector<int64_t> &C, std::vector<int64_t> &S) {
    vector<III> v;
    for (int i = 0; i < N; i++) {
        v.emplace_back(III(D[i], II(D[i] - C[i], i)));
    }
    sort(v.begin(), v.end());
    vector<int64_t> dp(5002);
    for (int vi = 0; vi < N; ++vi) {
        int64_t i = v[vi].second.second;
        for (int64_t day = D[i] - C[i] + 1; day >= 1; --day) {
            dp[day + C[i] - 1] = max(dp[day + C[i] - 1], dp[day - 1] + S[i]);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
#if DEBUG
	freopen("in_1.txt", "r", stdin);
#endif
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> D(N), C(N), S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> D[i] >> C[i] >> S[i];
	}
	cout << solve(N, D, C, S) << endl;
	return 0;
}
