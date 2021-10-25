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

vector<int> solve(int H, int W, int64_t N, std::vector<int> r, std::vector<int> c, std::vector<int> a) {
	vector<int> ans(N);
	map<int, vector<int>> ord;
	for (int i = 0; i < N; ++i) {
		ord[-a[i]].emplace_back(i);
	}
	vector<int> rv(H), cv(W);
	for (auto kv : ord) {
		map<int, int> nr, nc;
		for (auto x : kv.second) {
			ans[x] = max(rv[r[x]], cv[c[x]]);
			nr[r[x]] = max(nr[r[x]], ans[x] + 1);
			nc[c[x]] = max(nc[c[x]], ans[x] + 1);
		}
		for (auto kv : nr) {
			rv[kv.first] = kv.second;
		}
		for (auto kv : nc) {
			cv[kv.first] = kv.second;
		}
	}
	return ans;
}

int main() {
	int H, W, N;
	std::cin >> H >> W >> N;
	std::vector<int> r(N), c(N), a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> r[i] >> c[i] >> a[i];
		--r[i]; --c[i];
	}
	vector<int> ans = solve(H, W, N, r, c, a);
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}
