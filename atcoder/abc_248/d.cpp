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

int main() {
	int N, Q, l, r, x, ans;
	cin >> N;
	map<int, vector<int>> m;
	for (int i = 0; i < N; i++) {
		cin >> x;
		m[x].emplace_back(i);
	}
	cin >> Q;
	for (int qq = 0; qq < Q; ++qq) {
		cin >> l >> r >> x;
		ans = 0;
		auto it = m.find(x);
		if (it != m.end()) {
			const vector<int>& v = it->second;
			ans = lower_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l - 1);
		}
		cout << ans << endl;
	}
	return 0;
}
