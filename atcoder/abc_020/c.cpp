#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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
typedef long double LD;
typedef pair<LL, LL> II;
typedef pair<LL, II> III;
typedef priority_queue<III, vector<III>, greater<>> Queue;
static const LL INF = 1LL << 60;

const int dy[4] = { 0, -1, 0, 1 };
const int dx[4] = { -1, 0, 1, 0 };

void solve(long long H, long long W, long long T, std::vector<std::string> &s) {
	LL ans = 0;
	int sy = -1, sx = -1, ey = -1, ex = -1;
	for (int i = 0; i < H; i++) {
		if (sy < 0) {
			sx = (int)s[i].find('S');
			if (sx >= 0) sy = i;
		}
		if (ey < 0) {
			ex = (int)s[i].find('G');
			if (ex >= 0) ey = i;
		}
	}

	auto possible = [&](LL t) {
		vector<vector<LL>> min_cost(H, vector<LL>(W, INF));
		vector<III> q(1, III(0, II(sy, sx)));
		while (!q.empty()) {
			vector<III> nq;
			for (auto kv : q) {
				LL cost = kv.first, y = kv.second.first, x = kv.second.second;
				if (y == ey && x == ex) {
					return true;
				}
				for (int dir = 0; dir < 4; ++dir) {
					LL ny = y + dy[dir], nx = x + dx[dir];
					if (ny >= 0 && ny < H && nx >= 0 && nx < W) {
						LL next_cost = cost + (s[ny][nx] == '#' ? t : 1);
						if (next_cost <= T && next_cost < min_cost[ny][nx]) {
							min_cost[ny][nx] = next_cost;
							nq.emplace_back(III(next_cost, II(ny, nx)));
						}
					}
				}
			}
			q = nq;
		}
		return false;
	};
	LL left = 1, right = 1000000000;
	while (right - left > 1) {
		LL mid = (left + right) / 2;
		if (possible(mid)) {
			left = mid;
		} else {
			right = mid;
		}
	}
	cout << left << endl;
}

int main() {
    long long H;
	scanf("%lld", &H);
	long long W;
	scanf("%lld", &W);
	long long T;
	scanf("%lld", &T);
	std::vector<std::string> s(H);
	for (int i = 0; i < H; i++) {
		std::cin >> s[i];
	}
	solve(H, W, T, s);
	return 0;
}
