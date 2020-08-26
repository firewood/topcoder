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

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

static const int dx[4] = { -1,1,0,0 };
static const int dy[4] = { 0,0,-1,1 };

void solve(long long h, long long w, std::vector<std::string> c) {
	bool ans = false;
	int sh = -1, sw = -1, eh = -1, ew = -1;
	for (int i = 0; i < h; i++) {
		if (sh < 0) {
			sw = (int)c[i].find('s');
			if (sw >= 0) sh = i;
		}
		if (eh < 0) {
			ew = (int)c[i].find('g');
			if (ew >= 0) eh = i;
		}
	}
	Queue q;
	q.emplace(III(0, II(sh, sw)));
	vector<vector<LL>> min_cost(h, vector<LL>(w, INF));
	min_cost[sh][sw] = 0;
	while (!q.empty()) {
		III top = q.top();
		LL cost = top.first, y = top.second.first, x = top.second.second;
		if (y == eh && x == ew) {
			ans = cost <= 2;
			break;
		}
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			LL ny = y + dy[dir], nx = x + dx[dir];
			if (ny >= 0 && ny < h && nx >= 0 && nx < w) {
				LL next_cost = cost + (c[ny][nx] == '#');
				if (next_cost < min_cost[ny][nx]) {
					min_cost[ny][nx] = next_cost;
					q.emplace(III(next_cost, II(ny, nx)));
				}
			}
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
}

int main() {
    long long H;
	scanf("%lld", &H);
	long long W;
	scanf("%lld", &W);
	std::vector<std::string> c(H);
	for(int i = 0 ; i < H ; i++){
		std::cin >> c[i];
	}
	solve(H, W, c);
	return 0;
}
