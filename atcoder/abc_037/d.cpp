// D.

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

static const int MOD = 1000000007;

struct modll {
	long long x;
	modll() { }
	modll(long long _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(const modll &r) { return (x + r.x) % MOD; }
	modll operator+=(const modll &r) { return x = (x + r.x) % MOD; }
	modll operator-(const modll &r) { return (x + MOD - r.x) % MOD; }
	modll operator-=(const modll &r) { return x = (x + MOD - r.x) % MOD; }
	modll operator*(const modll &r) { return (x * r.x) % MOD; }
	modll operator*(int r) { return (x * r) % MOD; }
	modll operator*=(const modll &r) { return x = (x * r.x) % MOD; }
	modll inverse() {
		modll r = 1, a = x;
		for (int b = MOD - 2; b; b >>= 1) {
			if (b & 1) {
				r *= a;
			}
			a *= a;
		}
		return r;
	}
};

int main(int argc, char *argv[]) {
	int H, W;
	cin >> H >> W;
	int a[1000][1000];
	modll dp[1000][1000];
	vector<pair<int, pair<int, int> > > v;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> a[i][j];
			v.push_back(make_pair(a[i][j], make_pair(i, j)));
			dp[i][j] = 1;
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i != v.size(); ++i) {
		int row = v[i].second.first, col = v[i].second.second;
		int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
		for (int d = 0; d < 4; ++d) {
			int y = row + dy[d], x = col + dx[d];
			if (x >= 0 && x < W && y >= 0 && y < H && a[row][col] < a[y][x]) {
				dp[y][x] += dp[row][col];
			}
		}
	}

	modll ans = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			ans += dp[i][j];
		}
	}
	cout << ans << endl;
	return 0;
}
