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

static const int64_t INF = 1LL << 60;

int64_t solve(int64_t N, std::string S, std::vector<int64_t> W) {
	vector<int64_t> a, b;
	for (int i = 0; i < N; ++i) {
		if (S[i] == '0') {
			a.emplace_back(W[i]);
		} else {
			b.emplace_back(W[i]);
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int64_t ac = a.size(), bc = b.size(), ai = 0, bi = 0, ans = bc - bi;
	a.emplace_back(INF);
	b.emplace_back(INF);
	while (ai < ac || bi < bc) {
		int64_t x = min(a[ai], b[bi]);
		while (a[ai] == x) {
			++ai;
		}
		while (b[bi] == x) {
			++bi;
		}
		ans = max(ans, ai + bc - bi);
	}
	return ans;
}

int main() {
	int64_t N;
	std::string S;
	std::cin >> N >> S;
	std::vector<int64_t> W(N);
	for (int i = 0; i < N; i++) {
		std::cin >> W[i];
	}
	cout << solve(N, S, W) << endl;
	return 0;
}
