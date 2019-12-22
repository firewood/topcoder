// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int n, u, v, ans, ami;
vector<vector<int>> e;
vector<int> ad;
vector<int> bd;
vector<int> cd;

void dfs1(int n, int d) {
	if (bd[n] >= 0) return;
	bd[n] = d;
	for (int nx : e[n]) {
		dfs1(nx, d + 1);
	}
}

void dfs2(int n, int d) {
	if (ad[n] >= 0 || d > bd[n]) return;
	ad[n] = d;
	ans = max(ans, d);
	if (d >= bd[n]) return;
	if (ami < 0 || bd[n] < bd[ami]) {
		ami = n;
	}
	for (int nx : e[n]) {
		dfs2(nx, d + 1);
	}
}

void dfs3(int n, int d) {
	if (d <= cd[n] || d > bd[n]) return;
	cd[n] = d;
	ans = max(ans, d);
	if (d >= bd[n]) return;
	for (int nx : e[n]) {
		dfs3(nx, d + 1);
	}
}

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		ans = 0, n = -1, ami = -1;
		cin >> n >> u >> v;
		if (n <= 0) return 0;
		e.clear();
		e.resize(n);
		for (int i = 1; i < n; ++i) {
			int a, b;
			cin >> a >> b;
			e[a - 1].push_back(b - 1);
			e[b - 1].push_back(a - 1);
		}
		ad = vector<int>(n, -1);
		bd = vector<int>(n, -1);
		cd = vector<int>(n, -1);
		dfs1(v - 1, 0);
		dfs2(u - 1, 0);
		if (ami >= 0) {
			dfs3(ami, ad[ami]);
		}
		cout << ans << endl;
	}
	return 0;
}
