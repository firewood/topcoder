// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, k, c;
		cin >> n >> k >> c;
		if (n < 0) return 0;
		string s;
		cin >> s;
		++c;
		vector<int> fdp(n + 2), rdp(n + 2), mi(n + 2), lp(n + 2);
		for (int i = 0; i < n; ++i) {
			int w = s[i] == 'o';
			if (i >= c) {
				w += fdp[i - c];
			}
			if (i > 0) {
				w = max(w, fdp[i - 1]);
			}
			fdp[i] = w;
			if (i > 0) {
				mi[i] = mi[i - 1];
				if (fdp[i - 1] < fdp[i]) {
					mi[i] = i;
				}
			}
		}
		int last = n;
		lp[n] = last;
		for (int i = n - 1; i >= 0; --i) {
			lp[i] = last;
			int w = s[i] == 'o';
			if (w) last = i;
			if (i + c < n) {
				w += rdp[i + c];
			}
			if (i < n - 1) {
				w = max(w, rdp[i + 1]);
			}
			rdp[i] = w;
		}
		for (int i = 0; i < n; ++i) {
			if (s[i] != 'o') {
				continue;
			}
			if (!i) {
				int wd = rdp[i + 1];
				if (wd < k) {
					cout << i + 1 << endl;
				}
			} else {
				int pi = mi[i - 1];
				int wd = fdp[pi];
				int ni = min(n, max(pi + c, i + 1));
				wd += rdp[ni];
				if (wd < k) {
					cout << i + 1 << endl;
				}
			}
		}
	}
	return 0;
}
