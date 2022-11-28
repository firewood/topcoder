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

static map<II, int64_t> memo;
vector<int64_t> a, b;

int64_t solve(int start, int end) {
	if (start >= end) return 0;
	II key(start, end);
	if (memo.find(key) == memo.end()) {
		int64_t r = max(a[start] + a[end - 1], b[start] + b[end - 1]) + solve(start + 1, end - 1);
		for (int len = 2; start + len < end; len += 2) {
			r = max(r, solve(start, start + len) + solve(start + len, end));
		}
		memo[key] = r;
	}
	return memo[key];
}

int64_t solve(int64_t N, std::vector<int64_t> A, std::vector<int64_t> B) {
	int64_t ans = accumulate(A.begin(), A.end(), int64_t(0)), sum = ans;
	vector<vector<int64_t>> v(2);
	for (int i = 0; i < N; ++i) {
		v[i % 2].emplace_back(B[i] - A[i]);
	}
	for (int i = 0; i < 2; ++i) {
		sort(v[i].rbegin(), v[i].rend());
	}
	for (int i = 0; i < N / 2; ++i) {
		sum += v[0][i] + v[1][i];
		ans = max(ans, sum);
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<int64_t> B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}
	cout << solve(N, A, B) << endl;
	return 0;
}
