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

map<int64_t, int64_t> memo;

int64_t dfs(int64_t x, int64_t i, const vector<int64_t> &a) {
	if (i >= a.size()) {
		return x / a.back();
	}
	if (memo.find(x) == memo.end()) {
		int64_t p = x % a[i], q = a[i] - p;
		memo[x] = min(p / a[i - 1] + dfs(x - p, i + 1, a), q / a[i - 1] + dfs(x + q, i + 1, a));
	}
	return memo[x];
}

int64_t solve(int64_t N, int64_t X, const vector<int64_t> &A) {
	memo[0] = 0;
	return dfs(X, 1, A);
}

int main() {
	int64_t N, X;
	std::cin >> N >> X;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, X, A) << endl;
	return 0;
}
