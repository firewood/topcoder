// D.

#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

string solve(int n, string s) {
	for (int a = 0; a <= 1; ++a) {
		for (int b = 0; b <= 1; ++b) {
			bool ok = true;
			vector<int> t(n, -1);
			t[0] = a;
			t[n - 1] = b;
			for (int j = 0; j < n; ++j) {
				bool same = s[j] == 'o';
				int prev = t[(j - 1 + n) % n];
				int& next = t[(j + 1) % n];
				if (next == -1) {
					next = t[j] ^ !same ^ prev;
				} else if ((same ^ t[j]) != (next == prev)) {
					ok = false;
				}
			}
			if (ok) {
				string ans;
				for (int i = 0; i < n; ++i) {
					ans += t[i] ? 'W' : 'S';
				}
				return ans;
			}
		}
	}
	return "-1";
}

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	cout << solve(n, s) << endl;
	return 0;
}
