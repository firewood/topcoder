// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	while (true) {
		string s;
		cin >> s;
		LL k = -1;
		cin >> k;
		if (s.empty() || k <= 0) break;
		int len = s.length();
		int f;
		for (f = 0; f < len; ++f) {
			if (s[0] != s[f]) break;
		}
		LL ans = 0;
		if (f == len) {
			ans = (k * len) / 2;
		} else {
			ans = k * (f / 2);
			char prev = s[f - 1];
			int cnt = 0;
			for (int i = f; i < len; ++i) {
				if (s[i] != prev) {
					cnt = 0;
				}
				if ((++cnt % 2) == 0) {
					ans += k;
				}
				prev = s[i];
			}
			if (s[0] == s[len - 1] && (f % 2) == 1 && (cnt % 2) == 1) {
				ans += k - 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
