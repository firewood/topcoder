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

int64_t solve(int64_t N, int64_t W, std::vector<int64_t> A, std::vector<int64_t> B) {
	int64_t ans = 0, r = W;
	vector<II> v;
	for (int i = 0; i < N; ++i) {
		v.emplace_back(II(A[i], B[i]));
	}
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < N; ++i) {
		int64_t c = min(v[i].second, r);
		ans += v[i].first * c;
		r -= c;
	}
	return ans;
}

int main() {
	int64_t N, W;
	std::cin >> N >> W;
	std::vector<int64_t> A(N), B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i] >> B[i];
	}
	cout << solve(N, W, A, B) << endl;
	return 0;
}
