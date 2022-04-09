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

static const int64_t INF = 1LL << 60;

int64_t solve(int64_t N, int64_t K, std::vector<int64_t> A) {
	int64_t ans = INF;
	vector<II> a, b;
	for (int i = 0; i < N; ++i) {
		if (i < K) {
			a.emplace_back(II(A[i], i));
		} else {
			b.emplace_back(II(A[i], i));
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int64_t ai = 0, bi = 0, right = -1;
	while (bi < b.size()) {
		if (ai < a.size() && a[ai].first < b[bi].first) {
			right = max(right, a[ai].second);
			++ai;
		} else {
			if (right >= 0) {
				ans = min(ans, b[bi].second - right);
			}
			++bi;
		}
	}
	return ans < INF ? ans : -1;
}

int main() {
	int64_t N, K;
	std::cin >> N >> K;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, K, A) << endl;
	return 0;
}
