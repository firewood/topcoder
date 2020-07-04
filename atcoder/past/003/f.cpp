// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j) {
			a[i] |= 1 << (s[j] - 'a');
		}
	}
	string ans(n, 'a');
	for (int i = 0; i <= n / 2; ++i) {
		int f = a[i] & a[n - i - 1];
		if (!f) {
			ans = "-1";
			break;
		}
		for (int j = 0; j < 26; ++j) {
			if ((1 << j) & f) {
				ans[i] = ans[n - i - 1] = ('a' + j);
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
