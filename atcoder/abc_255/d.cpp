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

vector<int64_t> solve(int64_t N, int64_t Q, std::vector<int64_t> A, std::vector<int64_t> X) {
	vector<int64_t> ans(Q), sum(N + 1);
	sort(A.begin(), A.end());
	for (int i = 0; i < N; ++i) {
		sum[i + 1] = sum[i] + A[i];
	}
	for (int i = 0; i < Q; ++i) {
		int64_t pos = lower_bound(A.begin(), A.end(), X[i]) - A.begin();
		ans[i] = (pos * X[i] - sum[pos]) + sum[N] - sum[pos] - ((N - pos) * X[i]);
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
