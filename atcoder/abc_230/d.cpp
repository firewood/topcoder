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

int64_t solve(int64_t N, int64_t D, std::vector<int64_t> L, std::vector<int64_t> R) {
	int64_t ans = 0, right = -1;
	vector<II> v;
	for (int i = 0; i < N; ++i) {
		v.emplace_back(II(R[i], L[i]));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; ++i) {
		if (v[i].second < right) {
			continue;
		}
		++ans;
		right = v[i].first + D;
	}
	return ans;
}

int main() {
	int64_t N, D;
	std::cin >> N >> D;
	std::vector<int64_t> L(N), R(N);
	for (int i = 0; i < N; i++) {
		std::cin >> L[i] >> R[i];
	}
	cout << solve(N, D, L, R) << endl;
	return 0;
}
