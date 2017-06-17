#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	int n, tot = 0, vtbl[256] = {};
	vtbl['I'] = 1, vtbl['V'] = 5;
	vtbl['X'] = 10, vtbl['L'] = 50;
	vtbl['C'] = 100, vtbl['D'] = 500;
	vtbl['M'] = 1000;
	cin >> n;
	string s, digits = "IVXLCDM";
	for (int i = 0; i < n; ++i) {
		cin >> s;
		int prev = 5000;
		for (char c : s) {
			if (vtbl[c] > prev) {
				tot -= prev * 2;
			}
			tot += vtbl[c];
			prev = vtbl[c];
		}
	}
	string ans;
	if (tot >= 4000) {
		ans = "ERROR";
	} else {
		for (int i = 6; i >= 0; --i) {
			while (tot >= vtbl[digits[i]]) {
				ans += digits[i];
				tot -= vtbl[digits[i]];
			}
			int j = 2 - (i % 2);
			if (i >= j && tot >= vtbl[digits[i]] - vtbl[digits[i - j]]) {
				ans += digits[i - j];
				ans += digits[i];
				tot -= vtbl[digits[i]] - vtbl[digits[i - j]];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
