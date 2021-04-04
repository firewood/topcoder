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

bool is_balanced(const string& s) {
	int c = 0;
	for (int i = 0; i < (int)s.length(); ++i) {
		if (s[i] == '(') {
			c += 1;
		} else if (s[i] == ')') {
			c -= 1;
			if (c < 0) return false;
		}
	}
	return c == 0;
}

vector<string> solve(int n, string t) {
	string x(n, '.');
	string y(n, '.');
	int xl = 0, xr = 0, yl = 0, yr = 0;
	for (int i = 0; i < n / 2; ++i) {
		if (t[i] == '1') {
			if (xl + yl > xr + yr) {
				x[i] = ')';
				--xl;
				y[i] = ')';
				--yl;
			} else {
				x[i] = '(';
				++xl;
				y[i] = '(';
				++yl;
			}
		} else {
			if (xl >= yl) {
				x[i] = ')';
				--xl;
				y[i] = '(';
				++yl;
			} else {
				x[i] = '(';
				++xl;
				y[i] = ')';
				--yl;
			}
		}
		if (t[n - i - 1] == '1') {
			if (xr + yr > xl + yl) {
				x[n - i - 1] = '(';
				--xr;
				y[n - i - 1] = '(';
				--yr;
			} else {
				x[n - i - 1] = ')';
				++xr;
				y[n - i - 1] = ')';
				++yr;
			}
		} else {
			if (xr >= yr) {
				x[n - i - 1] = '(';
				--xr;
				y[n - i - 1] = ')';
				++yr;
			} else {
				x[n - i - 1] = ')';
				++xr;
				y[n - i - 1] = '(';
				--yr;
			}
		}
	}
	if (is_balanced(x) && is_balanced(y)) {
		return { x, y };
	}
	return {};
}

int main() {
	int t, n;
	string s;
	cin >> t;
	for (int q = 0; q < t; ++q) {
		cin >> n >> s;
		vector<string> ans = solve(n, s);
		if (ans.empty()) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			cout << ans[0] << endl;
			cout << ans[1] << endl;
		}
	}
	return 0;
}
