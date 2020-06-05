// H.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> II;

int dist(const II& a, const II& b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(int argc, char* argv[]) {
	int h, w;
	cin >> h >> w;
	vector<string> b(h);
	II s, g;
	set<II> p[11];
	for (int i = 0; i < h; ++i) {
		cin >> b[i];
		for (int j = 0; j < w; ++j) {
			switch (b[i][j]) {
			case 'S':
				s = II(i, j);
				break;
			case 'G':
				g = II(i, j);
				break;
			default:
				p[b[i][j] - '0'].emplace(II(i, j));
				break;
			}
		}
	}
	p[0].emplace(s);
	p[10].emplace(g);
	map<II, int> m;
	bool ok = true;
	for (int i = 1; i <= 9; ++i) {
		if (p[i].empty()) {
			ok = false;
		}
	}
	int ans = -1;
	if (ok) {
		ans = 0;
		for (int i = 1; i <= 10; ++i) {
			for (auto dst : p[i]) {
				int d = 1 << 30;
				for (auto src : p[i - 1]) {
					d = min(d, m[src] + dist(src, dst));
				}
				m[dst] = d;
			}
		}
		ans = m[g];
	}
	cout << ans << endl;
	return 0;
}
