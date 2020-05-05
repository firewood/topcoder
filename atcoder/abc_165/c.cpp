// C.

#include <iostream>
#include <sstream>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

typedef long long LL;

int n, m, q;
vector<tuple<int, int, int, int>> v;
LL ans;

void dfs(int c, vector<int> &seq) {
	if (c < n) {
		for (int d = seq[c - 1]; d <= m; ++d) {
			seq[c] = d;
			dfs(c + 1, seq);
		}
	} else {
		LL score = 0;
		for (int i = 0; i < q; ++i) {
			if (seq[get<1>(v[i])] - seq[get<0>(v[i])] == get<2>(v[i])) {
				score += get<3>(v[i]);
			}
		}
		ans = max(ans, score);
	}
}

int main(int argc, char* argv[]) {
	cin >> n >> m >> q;
	for (int i = 0; i < q; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v.emplace_back(a - 1, b - 1, c, d);
	}
	for (int i = 1; i <= m; ++i) {
		vector<int> seq(n, i);
		dfs(1, seq);
	}
	cout << ans << endl;
	return 0;
}
