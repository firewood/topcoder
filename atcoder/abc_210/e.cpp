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

int64_t gcd(int64_t a, int64_t b) { return b ? gcd(b, a % b) : a; }

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> A, std::vector<int64_t> C) {
	int64_t ans = 0, r = N;
	vector<pair<int64_t, int64_t>> v;
	for (int i = 0; i < M; ++i) {
		v.push_back({ C[i], A[i] });
	}
	sort(v.begin(), v.end());
	for (auto kv : v) {
		int64_t nr = gcd(r, kv.second);
		ans += (r - nr) * kv.first;
		r = nr;
	}
	return r == 1 ? ans : -1;
}

int main() {
#if DEBUG || _DEBUG
	freopen("in.txt", "r", stdin);
//	freopen("in_1.txt", "r", stdin);
#endif
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> A(M), C(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> C[i];
	}
	cout << solve(N, M, std::move(A), std::move(C)) << endl;
	return 0;
}
