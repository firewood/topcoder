// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL n;
	cin >> n;
	vector<LL> a, b;
	for (int i = 0; i < (1 << 16); ++i) {
		LL x = 0;
		for (int b = 0; b < 16; ++b) {
			if (i & (1 << b)) {
				x += 1LL << (b * 2);
			}
		}
		a.push_back(x);
		b.push_back(x * -2);
	}
	string ans;
	set<LL> s(b.begin(), b.end());
	for (LL x : a) {
		set<LL>::const_iterator it = s.find(n - x);
		if (it != s.end()) {
			LL y = x | (*it * -1);
			while (y) {
				ans = (y & 1 ? '1' : '0') + ans;
				y >>= 1;
			}
			break;
		}
	}
	cout << (ans.empty() ? "0" : ans) << endl;
	return 0;
}
