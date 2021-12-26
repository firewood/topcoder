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

string solve(int64_t n, std::vector<int64_t> R, std::vector<int64_t> C, int64_t q, std::vector<int64_t> r, std::vector<int64_t> c) {
	string ans;
	for (int i = 0; i < q; ++i) {
		bool black = R[r[i]] + C[c[i]] >= n + 1;
		ans += black ? '#' : '.';
	}
	return ans;
}

int main() {
	int64_t n, q;
	std::cin >> n;
	std::vector<int64_t> R(n);
	for (int i = 0; i < n; i++) {
		std::cin >> R[i];
	}
	std::vector<int64_t> C(n);
	for (int i = 0; i < n; i++) {
		std::cin >> C[i];
	}
	std::cin >> q;
	std::vector<int64_t> r(q), c(q);
	for (int i = 0; i < q; i++) {
		std::cin >> r[i] >> c[i];
		--r[i];
		--c[i];
	}
	cout << solve(n, R, C, q, r, c) << endl;
	return 0;
}
