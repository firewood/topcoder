// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	while (true) {
		LL n = -1;
		cin >> n;
		if (n <= 0) break;
		string s;
		cin >> s;
		int len = s.length();
		int ans = 0;
		for (int i = 1; i < len; ++i) {
			int cnt = 0;
			for (int j = 0; i + j < len; ++j) {
				if (s[j] == s[i + j]) {
					ans = max(ans, ++cnt);
					if (cnt >= i) {
						break;
					}
				} else {
					cnt = 0;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
