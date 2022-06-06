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

vector<int64_t> solve(int64_t H, int64_t W, int64_t C, int64_t Q, std::vector<int64_t> t, std::vector<int64_t> n, std::vector<int64_t> c) {
	vector<int64_t> cnt(C);
	set<int> hs, ws;
	for (int i = Q - 1; i >= 0; --i) {
		if (t[i] == 1) {
			if (hs.find(n[i]) == hs.end()) {
				hs.insert(n[i]);
				cnt[c[i]] += W - ws.size();
			}
		} else {
			if (ws.find(n[i]) == ws.end()) {
				ws.insert(n[i]);
				cnt[c[i]] += H - hs.size();
			}
		}
	}
	return cnt;
}

int main() {
	int64_t H, W, C, Q;
	std::cin >> H >> W >> C >> Q;
	std::vector<int64_t> t(Q), n(Q), c(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> t[i] >> n[i] >> c[i];
		--n[i];
		--c[i];
	}
	vector<int64_t> ans = solve(H, W, C, Q, t, n, c);
	for (int i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
