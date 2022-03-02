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

void solve(int N, int Q, std::vector<int> a, std::vector<int> x, std::vector<int> k) {
	map<int, vector<int>> m;
	for (int i = 0; i < N; ++i) {
		m[a[i]].emplace_back(i + 1);
	}
	for (int i = 0; i < Q; ++i) {
		const vector<int>& v = m[x[i]];
		int ans = k[i] <= v.size() ? v[k[i] - 1] : -1;
		cout << ans << endl;
	}
}

int main() {
	int N, Q;
	std::cin >> N >> Q;
	std::vector<int> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	std::vector<int> x(Q), k(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> x[i] >> k[i];
	}
	solve(N, Q, a, x, k);
	return 0;
}
