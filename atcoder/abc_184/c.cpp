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

typedef long long LL;

int solve(std::vector<int> &r, std::vector<int> &c) {
	LL ans = 0;
	LL x = abs(c[1] - c[0]), y = abs(r[1] - r[0]);
	LL h = (x + y) / 2;
	if (h >= 3) {
		++ans;
		x = abs(x - h);
		y = abs(y - h);
	}
	if (x > y) swap(x, y);
	if (x == y) {
		ans += x >= 1;
	} else {
		ans += 1 + !(x <= 2 && y <= 2 || x == 0 && y == 3);
	}
	return ans;
}

int solve2(std::vector<int>& r, std::vector<int>& c) {
	const int dy[4] = { -1, -1, 1, 1 };
	const int dx[4] = { -1, 1, -1, 1 };
	set<pair<int, int>> s;
	vector<pair<int, int>> q;
	q.emplace_back(make_pair(r[0], c[0]));
	for (int i = 0; i < 3; ++i) {
		vector<pair<int, int>> nq;
		for (auto kv : q) {
			if (kv.first == r[1] && kv.second == c[1]) return i;
			for (int y = kv.first - 3; y <= kv.first + 3; ++y) {
				for (int x = kv.second - 3; x <= kv.second + 3; ++x) {
					if (abs(kv.first - y) >= 3 && x != kv.second) continue;
					if (abs(kv.second - x) >= 3 && y != kv.first) continue;
					if (s.find(make_pair(y, x)) == s.end()) {
						s.insert(make_pair(y, x));
						nq.emplace_back(make_pair(y, x));
					}
				}
			}
			for (int d = 3; d <= 8; ++d) {
				for (int dir = 0; dir < 4; ++dir) {
					int y = kv.first + dy[dir] * d, x = kv.second + dx[dir] * d;
					if (s.find(make_pair(y, x)) == s.end()) {
						s.insert(make_pair(y, x));
						nq.emplace_back(make_pair(y, x));
					}
				}
			}
		}
		q = nq;
	}
	return 3;
}

int main() {
	std::vector<int> r(2), c(2);
	for (int i = 0; i < 2; i++) {
		std::cin >> r[i];
		std::cin >> c[i];
	}
	int ans = solve(r, c);
	cout << ans << endl;

#if defined(_WIN32) && defined(NDEBUG)
	for (int t = 0; t < 1000; ++t) {
		r = { (rand() % 10) - 5, (rand() % 10) - 5 };
		c = { (rand() % 10) - 5, (rand() % 10) - 5 };
		int x = solve(r, c);
		int y = solve2(r, c);
		if (x != y) {
			printf("FAILED! %d,%d,%d,%d\n", r[0], c[0], r[1], c[1]);
			++x;
		}
	}
#endif
	return 0;
}
