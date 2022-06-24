// Google Code Jam 2022 Round 2
// Problem A. Spiraling Into Control (3pts, 4pts, 13pts)

#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <cassert>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;

vector<II> solve(LL N, LL K) {
	vector<II> ans;

	LL r = N * N - 1 - K;
	if (K % 2) {
		return {};
	}
	vector<LL> v;
	LL sum = 0, x = 1;
	for (LL i = 3; i <= N; i += 2) {
		v.emplace_back(i * i - (i - 2) * (i - 2));
	}
	reverse(v.begin(), v.end());

	LL pos = 1, d = v[0], fwd = 1;
	for (LL i = N; i >= 3; i -= 2) {
		for (int j = 0; j < 4; ++j) {
			d -= 2;
			if (pos >= fwd && d <= r && d > 0) {
				ans.emplace_back(II(pos + 1, pos + d + 2));
				fwd = pos + d + 2;
				r -= d;
			}

			pos += i - 1;
		}
	}

	if (r > 0) {
		return {};
	}

	return ans;
}

int main(int argc, char* argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		LL N, K;
		cin >> N >> K;
		cout << "Case #" << t << ": ";
		vector<II> ans = solve(N, K);
		if (ans.empty()) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			cout << ans.size() << endl;
			if (!ans.empty()) {
				for (size_t i = 0; i < ans.size(); ++i) {
					cout << ans[i].first << " " << ans[i].second << endl;
				}
			}
		}
	}
	return 0;
}
