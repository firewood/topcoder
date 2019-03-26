// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef long long LL;
static const LL MOD = 1000000007;

int n;
map<string, LL> memo[102];

bool check(const string &s) {
	for (int i = 0; i < 4; ++i) {
		string t = s;
		if (i) {
			t[i - 1] = s[i];
			t[i] = s[i - 1];
		}
		if (t.find("AGC") != string::npos) {
			return false;
		}
	}
	return true;
}

LL dfs(int pos, const string &last) {
	map<string, LL> &m = memo[pos];
	if (pos == n) {
		return 1;
	}
	if (m.find(last) == m.end()) {
		LL cnt = 0;
		const string T = "AGCT";
		for (char c : T) {
			if (check(last + c)) {
				cnt = (cnt + dfs(pos + 1, last.substr(1) + c)) % MOD;
			}
		}
		m[last] = cnt;
	}
	return m[last];
}

int main(int argc, char *argv[]) {
	cin >> n;
	LL ans = dfs(0, "ZZZ");
	cout << ans << endl;
	return 0;
}
