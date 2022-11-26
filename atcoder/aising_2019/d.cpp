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

vector<int64_t> solve(int64_t N, int64_t Q, std::vector<int64_t> A, std::vector<int64_t> X) {
	vector<int64_t> ans(Q), all_sum(N + 2), skip_sum(N + 2);
	for (int i = 0; i < N; ++i) {
		all_sum[i + 1] = A[i] + all_sum[i];
		skip_sum[i + 1] = A[i] + (i >= 2 ? skip_sum[i - 1] : 0);
	}
	vector<II> v;
	for (int i = 0; i < Q; ++i) {
		v.emplace_back(II(X[i], i));
	}
	sort(v.begin(), v.end());
	int64_t y = 0;
	for (auto kv : v) {
		int64_t x = kv.first, a = A[kv.second];
		while (y < N && A[y] < x) {
			++y;
		}
		while (y < N) {
			int64_t first = N - y;
			int64_t second = y - (lower_bound(A.begin(), A.end(), max(int64_t(1), x - (A[y] - x))) - A.begin()) + 1;
			if (first > second) {
				++y;
			} else {
				break;
			}
		}
		int64_t& result = ans[kv.second];
		result = all_sum[N] - all_sum[y];
		int64_t remain = N - (N - y) * 2;
		if (remain >= 0) {
			result += skip_sum[remain];
		}
	}
	return ans;
}

int main() {
	int64_t N, Q;
	std::cin >> N >> Q;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<int64_t> X(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> X[i];
	}
	vector<int64_t> ans = solve(N, Q, A, X);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
