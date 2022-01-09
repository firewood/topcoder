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

typedef long double LD;
typedef pair<int64_t, int64_t> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;

vector<int> solve(int N, int D, int K, std::vector<int> L, std::vector<int> R, std::vector<int> S, std::vector<int> T) {
	vector<int> ans(K);
	for (int i = 0; i < K; ++i) {
		int left = S[i], right = S[i], day;
		for (day = 0; day < D; ++day) {
			if (left <= T[i] && T[i] <= right) {
				break;
			}
			if (R[day] >= left) {
				left = min(left, L[day]);
			}
			if (L[day] <= right) {
				right = max(right, R[day]);
			}
		}
		ans[i] = day;
	}
	return ans;
}

int main() {
	int64_t N, D, K;
	std::cin >> N >> D >> K;
	std::vector<int> L(D), R(D);
	for (int i = 0; i < D; i++) {
		std::cin >> L[i] >> R[i];
	}
	std::vector<int> S(K), T(K);
	for (int i = 0; i < K; i++) {
		std::cin >> S[i] >> T[i];
	}
	vector<int> ans = solve(N, D, K, L, R, S, T);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
