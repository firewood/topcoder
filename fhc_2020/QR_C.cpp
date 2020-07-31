//
// Facebook Hacker Cup 2020 Qualification Round
// C. Timber
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;

LL solve(int n, vector<II> trees) {
	sort(trees.begin(), trees.end());
	unordered_map<int, LL> m;
	for (auto kv : trees) {
		m[kv.first + kv.second] = max(m[kv.first + kv.second], m[kv.first] + kv.second);
		m[kv.first] = max(m[kv.first], m[kv.first - kv.second] + kv.second);
	}
	LL ans = 0;
	for (auto kv : m) {
		ans = max(ans, kv.second);
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int T, n;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> n;
		vector<II> logs(n);
		for (int i = 0; i < n; ++i) {
			cin >> logs[i].first >> logs[i].second;
		}
		LL ans = solve(n, logs);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
