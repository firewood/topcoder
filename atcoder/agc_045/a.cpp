// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long LL;

// ë|Ç´èoÇµñ@
bool possible(LL t, vector<LL> a) {
	if (a.empty()) return t == 0;
	LL x = 0;
	int st = 0;
	int sz = (int)a.size();
	sort(a.rbegin(), a.rend());
	vector<int> bp(64, -1);
	for (LL b = 60; b >= 0; --b) {
		LL f = 1LL << b;
		if (!(a[st] & f)) continue;
		for (int i = 0; i < sz; ++i) {
			if (i != st && (a[i] & f) != 0) a[i] ^= a[st];
		}
		bp[b] = st++;
		if (st >= sz) break;
		sort(a.rbegin(), a.rbegin() + sz - st);
	}
	for (LL b = 60; b >= 0; --b) {
		LL f = 1LL << b;
		if ((f & t) != 0 && (f & x) == 0 && bp[b] >= 0) {
			x ^= a[bp[b]];
		}
	}
	return t == x;
}

int main(int argc, char* argv[]) {
	LL t, n;
	cin >> t;
	for (LL tt = 0; tt < t; ++tt) {
		cin >> n;
		vector<LL> a(n);
		for (LL i = 0; i < n; ++i) {
			cin >> a[i];
		}
		string s;
		cin >> s;
		int ans = 0;
		vector<LL> x;
		for (LL i = n - 1; i >= 0; --i) {
			if (s[i] != '0') {
				if (!possible(a[i], x)) {
					ans = 1;
					break;
				}
			} else {
				x.emplace_back(a[i]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
