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

typedef pair<int, int> II;

int solve(int H, int W, int N, int s_x, int s_y, int g_x, int g_y, std::vector<int> X, std::vector<int> Y) {
	map<int, set<int>> h, v;
	for (int i = 0; i < N; ++i) {
		h[X[i]].insert(-1);
		h[X[i]].insert(Y[i]);
		v[Y[i]].insert(-1);
		v[Y[i]].insert(X[i]);
	}
	set<II> s;
	s.insert(II(s_x, s_y));
	vector<II> q;
	q.emplace_back(II(s_x, s_y));
	for (int i = 0; !q.empty(); ++i) {
		vector<II> nq;
		for (auto kv : q) {
			int r = kv.first, c = kv.second;
			if (r == g_x && c == g_y) {
				return i;
			}
			if (h.find(r) != h.end()) {
				auto it = lower_bound(h[r].begin(), h[r].end(), c);
				--it;
				if (*it >= 0) {
					II key(r, *it + 1);
					if (s.find(key) == s.end()) {
						s.insert(key);
						nq.emplace_back(key);
					}
				}
				++it;
				if (it != h[r].end()) {
					II key(r, *it - 1);
					if (s.find(key) == s.end()) {
						s.insert(key);
						nq.emplace_back(key);
					}
				}
			}
			if (v.find(c) != v.end()) {
				auto it = lower_bound(v[c].begin(), v[c].end(), r);
				--it;
				if (*it >= 0) {
					II key(*it + 1, c);
					if (s.find(key) == s.end()) {
						s.insert(key);
						nq.emplace_back(key);
					}
				}
				++it;
				if (it != v[c].end()) {
					II key(*it - 1, c);
					if (s.find(key) == s.end()) {
						s.insert(key);
						nq.emplace_back(key);
					}
				}
			}
		}
		q = nq;
	}
	return -1;
}

int main() {
	int H, W, N, s_x, s_y, g_x, g_y;
	std::cin >> H >> W >> N >> s_x >> s_y >> g_x >> g_y;
	std::vector<int> X(N), Y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i] >> Y[i];
	}
	cout << solve(H, W, N, s_x, s_y, g_x, g_y, X, Y) << endl;
	return 0;
}
