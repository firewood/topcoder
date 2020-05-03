// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

typedef pair<int, int> II;
typedef pair<II, II> IIII;
typedef long long LL;

int main(int argc, char* argv[]) {
	int n, m, q;
	cin >> n >> m >> q;
	vector<IIII> v(q);
	for (int i = 0; i < q; ++i) {
		cin >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second;
		v[i].first.first -= 1;
		v[i].first.second -= 1;
	}
	vector<vector<int>> seq;
	for (int i = 1; i <= m; ++i) {
		seq.emplace_back(vector<int>(1, i));
	}
	for (int i = 2; i <= n; ++i) {
		vector<vector<int>> next;
		for (auto v : seq) {
			for (int d = v.back(); d <= m; ++d) {
				vector<int> w = v;
				w.emplace_back(d);
				next.emplace_back(w);
			}
		}
		seq = next;
	}
	LL ans = 0;
	for (auto a : seq) {
		LL score = 0;
		for (int i = 0; i < q; ++i) {
			if (a[v[i].first.second] - a[v[i].first.first] == v[i].second.first) {
				score += v[i].second.second;
			}
		}
		ans = max(ans, score);
	}
	cout << ans << endl;
	return 0;
}
