#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	string x = "good", y = "problem";
	for (int t = 0; t < T; ++t) {
		getline(cin, s);
		int len = (int)s.length();
		int ans = 1 << 30;
		for (int a = x.length(); a <= len - y.length(); ++a) {
			int cnt = 0;
			for (int b = 0; b < (int)y.length(); ++b) {
				cnt += s[a + b] != y[b];
			}
			for (int b = 0; b <= a - x.length(); ++b) {
				int tot = cnt;
				for (int c = 0; c < (int)x.length(); ++c) {
					tot += s[b + c] != x[c];
				}
				ans = min(ans, tot);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
