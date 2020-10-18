#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1 << 30;

const string ac = "atcoder";

int solve(string s) {
	int len = s.length();
	if (s > ac) {
		return 0;
	}
	for (int i = 1; i < len; ++i) {
		if (s[i] != 'a') {
			return i - (s[i] > 't');
		}
	}
	return -1;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		string s;
		cin >> s;
		int ans = solve(s);
		cout << ans << endl;
	}
	return 0;
}
