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

vector<int64_t> solve(int64_t N, vector<int64_t> S) {
	vector<int64_t> ans, x(2);
	for (int i = 0; i < N; ++i) {
		x.emplace_back(S[i] - x[i] - x[i + 1]);
	}
	vector<int64_t> mn(3, 1LL << 60);
	for (int i = 0; i < N + 2; ++i) {
		mn[i % 3] = min(mn[i % 3], x[i]);
	}
	int64_t a = -mn[0], b = -mn[1], c = mn[2];
	if (a + b <= c) {
		vector<int64_t> d({ a, b, -a - b });
		for (int i = 0; i < N + 2; ++i) {
			ans.emplace_back(x[i] + d[i % 3]);
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	vector<int64_t> ans = solve(N, S);
	if (!ans.empty()) {
		cout << "Yes" << endl;
		for (size_t i = 0; i < ans.size(); ++i) {
			if (i) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
