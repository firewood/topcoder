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
#include <atcoder/modint>

using namespace std;

using mint = atcoder::modint998244353;
const mint div2 = mint(2).inv();

mint solve(int N, int Q, std::vector<int> P, std::vector<int> V) {
	mint ans = 0;

	map<set<int>, mint> dp;
	dp[{}] = 1;

	for (int q = 0; q < Q; ++q) {
		map<set<int>, mint> next;
		int p = P[q], v = V[q];
		for (auto kv : dp) {
			{
				bool ok = true;
				set<int> ns = kv.first;
				for (auto x : kv.first) {
					int xx = abs(x), pp = P[xx - 1], vv = V[xx - 1];
					if (vv <= v) {
						if (x < 0) {
							ns.erase(x);
						}
					} else if (pp <= p || x < 0) {
						ok = false;
						break;
					}
				}
				if (ok) {
					ns.insert(-(q + 1));
					next[ns] += kv.second;
				}
			}
			{
				bool ok = true;
				set<int> ns = kv.first;
				for (auto x : kv.first) {
					int xx = abs(x), pp = P[xx - 1], vv = V[xx - 1];
					if (vv <= v) {
						if (x > 0) {
							ns.erase(x);
						}
					} else if (pp >= p || x > 0) {
						ok = false;
						break;
					}
				}
				if (ok) {
					ns.insert(q + 1);
					next[ns] += kv.second;
				}
			}
		}
		dp = next;
	}

	for (auto kv : dp) {
		ans += kv.second;
	}

	return ans;
}

int main() {
	int N, Q;
	std::cin >> N >> Q;
	std::vector<int> P(Q), V(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> P[i] >> V[i];
	}
	cout << solve(N, Q, P, V).val() << endl;
	return 0;
}
