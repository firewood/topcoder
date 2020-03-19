// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

typedef long long LL;

const LL MOD = 1000000007;

struct modll {
	long long x;
	modll() { }
	modll(int _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(int y) { return (x + y + MOD) % MOD; }
	modll operator+=(int y) { x = (x + y + MOD) % MOD; return *this; }
	modll operator-(int y) { return (x - y + MOD) % MOD; }
	modll operator-=(int y) { x = (x - y + MOD) % MOD; return *this; }
	modll operator*(int y) { return (x * y) % MOD; }
	modll operator*=(int y) { x = (x * y) % MOD; return *this; }
	modll operator/(int y) { return (x * modpow(y, MOD - 2)) % MOD; }
	modll operator/=(int y) { x = (x * modpow(y, MOD - 2)) % MOD; return *this; }
	static modll modinv(int a) { return modpow(a, MOD - 2); }
	static modll modpow(int a, int b) {
		modll x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

vector<vector<int>> e;
vector<modll> dp;

// tree DP
modll dfs(int parent, int node) {
	modll black = 1;
	modll white = 1;
	for (int next : e[node]) {
		if (next == parent) continue;
		white *= dfs(node, next);
		black *= dp[next];
	}
	dp[node] = white;
	return black + white;
}

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, a, b;
		cin >> n;
		if (n < 0) return 0;
		e.clear();
		e.resize(n);
		dp = vector<modll>(n, 0);
		for (int i = 0; i < n - 1; ++i) {
			cin >> a >> b;
			--a, --b;
			e[a].push_back(b);
			e[b].push_back(a);
		}
		modll ans = dfs(-1, 0);
		cout << ans << endl;
	}
	return 0;
}
