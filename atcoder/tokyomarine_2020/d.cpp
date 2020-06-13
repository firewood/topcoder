// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
typedef long long LL;
typedef pair<LL, LL> LLLL;

const int MAX_W = 100000;
const int THRESHOLD = 1 << 9;

vector<LL> v;
vector<LL> w;

vector<LLLL> calc(int node, LL max_weight) {
	int init_node = node;
	vector<LLLL> dp;
	dp.emplace_back(LLLL(0, 0));
	while (node > 0 && (init_node < THRESHOLD || node >= THRESHOLD)) {
		vector<LLLL> next = dp;
		for (auto kv : dp) {
			if (kv.first + w[node] > max_weight) continue;
			next.emplace_back(LLLL(kv.first + w[node], kv.second + v[node]));
		}
		dp = next;
		node /= 2;
	}
	return dp;
}

int main(int argc, char* argv[]) {
	int n, q, x, y;
	cin >> n;
	v.resize(n + 1);
	w.resize(n + 1);
	for (LL i = 1; i <= n; ++i) {
		cin >> v[i] >> w[i];
	}
	vector<vector<LL>> lower;
	if (n >= THRESHOLD) {
		lower.resize(THRESHOLD);
		vector<vector<LLLL>> dp(THRESHOLD);
		dp[0].emplace_back(LLLL(0, 0));
		for (int i = 1; i < THRESHOLD; ++i) {
			vector<LLLL> next = dp[i / 2];
			for (auto kv : dp[i / 2]) {
				if (kv.first + w[i] > MAX_W) continue;
				next.emplace_back(LLLL(kv.first + w[i], kv.second + v[i]));
			}
			if (i >= THRESHOLD / 2) {
				next.emplace_back(LLLL(MAX_W + 1, 0));
				sort(next.begin(), next.end());
				LL filled_index = 0, prev_max_value = 0;
				lower[i].resize(MAX_W + 1);
				for (auto kv : next) {
					for (LL j = filled_index; j < kv.first; ++j) {
						lower[i][j] = prev_max_value;
					}
					filled_index = kv.first;
					prev_max_value = max(prev_max_value, kv.second);
				}
			} else {
				dp[i] = next;
			}
		}
	}
	cin >> q;
	for (LL tt = 0; tt < q; ++tt) {
		cin >> x >> y;
		LL ans = 0;
		vector<LLLL> r = calc(x, y);
		if (x < THRESHOLD) {
			for (auto kv : r) {
				ans = max(ans, kv.second);
			}
		} else {
			while (x >= THRESHOLD) {
				x /= 2;
			}
			for (auto kv : r) {
				ans = max(ans, kv.second + lower[x][y - kv.first]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
