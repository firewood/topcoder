#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

int main() {
	string s, ans;
	cin >> s;
	int len = (int)s.length();
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			if (i != j && s[i] > 'a' && s[j] < 'z') {
				ans = s;
				ans[i] -= 1;
				ans[j] += 1;
			}
		}
	}
	if (ans.empty()) {
		if (len > 1 && s[0] == 'a') {
			ans = s.substr(1);
			ans[0] += 1;
		}
		if (len < 20 && s[0] > 'a') {
			ans = s;
			ans[0] -= 1;
			ans += 'a';
		}
	}
	cout << (ans.empty() ? "NO" : ans) << endl;
	return 0;
}
