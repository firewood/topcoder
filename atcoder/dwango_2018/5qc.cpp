// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	int n, q;
	cin >> n;
	string s;
	cin >> s;
	cin >> q;
	vector<int> k(q);
	for (int i = 0; i < q; ++i) {
		cin >> k[i];
	}
	int sz = (int)s.length();
	vector<LL> rc(n);
	for (int i = 0; i < q; ++i) {
		LL ans = 0, dc = 0, mc = 0, mt = 0;
		for (int j = 0; j < sz; ++j) {
			if (j >= k[i] && s[j - k[i]] == 'D') {
				--dc;
				mt -= mc;
			}
			if (j >= k[i] && s[j - k[i]] == 'M') {
				--mc;
			}
			switch (s[j]) {
			case 'D':
				++dc;
				break;
			case 'M':
				++mc;
				mt += dc;
				break;
			case 'C':
				ans += mt;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
