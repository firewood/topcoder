// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

typedef long long LL;
static const LL MOD = 1000000007LL;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	LL cnt[26] = {};
	for (int i = 0; i < n; ++i) {
		cnt[s[i] - 'a'] += 1;
	}
	LL ans = 1;
	for (int i = 0; i < 26; ++i) {
		ans = (ans * (cnt[i] + 1)) % MOD;
	}
	ans = (ans - 1 + MOD) % MOD;
	cout << ans << endl;
	return 0;
}
