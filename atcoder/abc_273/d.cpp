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

static const int INF = 1 << 30;

int get_prev(const map<int, set<int>>& m, int a, int b) {
	auto it = m.find(a);
	if (it != m.end()) {
		const set<int>& s = it->second;
		auto p = s.lower_bound(b);
		if (p != s.begin()) {
			return *--p + 1;
		}
	}
	return 0;
}

int get_next(const map<int, set<int>>& m, int a, int b) {
	auto it = m.find(a);
	if (it != m.end()) {
		const set<int>& s = it->second;
		auto p = s.upper_bound(b);
		if (p != s.end()) {
			return *p - 1;
		}
	}
	return INF;
}

int main() {
	int H, W, N, Q, rs, cs, r, c, len;
	string d;
	cin >> H >> W >> rs >> cs >> N;
	--rs; --cs;
	map<int, set<int>> mh, mv;
	for (int i = 0; i < N; i++) {
		std::cin >> r >> c;
		--r; --c;
		mh[r].insert(c);
		mv[c].insert(r);
	}
	r = rs, c = cs;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		cin >> d >> len;
		if (d == "L") {
			c = max(c - len, get_prev(mh, r, c));
		}
		if (d == "R") {
			c = min({ c + len, W - 1, get_next(mh, r, c) });
		}
		if (d == "U") {
			r = max(r - len, get_prev(mv, c, r));
		}
		if (d == "D") {
			r = min({ r + len, H - 1, get_next(mv, c, r) });
		}
		cout << (r + 1) << " " << (c + 1) << endl;
	}
	return 0;
}
