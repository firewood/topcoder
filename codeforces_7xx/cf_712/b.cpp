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
typedef long double LD;
typedef pair<LL, LL> II;
typedef pair<LL, II> III;

static const LL INF = 1LL << 60;

bool solve(int n, string a, string b) {
	vector<vector<int>> cnt(2, vector<int>(n + 1));
	for (int i = 0; i < n; ++i) {
		int c = a[i] - '0';
		cnt[c][i + 1] = cnt[c][i] + 1;
		cnt[!c][i + 1] = cnt[!c][i];
	}
	bool state = false;
	for (int i = n - 1; i >= 0; --i) {
		bool same = (a[i] == b[i]) ^ state;
		if (!same) {
			if (cnt[0][i + 1] != cnt[1][i + 1]) return false;
			state = !state;
		}
	}
	return true;
}

int main() {
	int t, n;
	string a, b;
	cin >> t;
	for (int q = 0; q < t; ++q) {
		cin >> n >> a >> b;
		bool ans = solve(n, a, b);
		cout << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}
