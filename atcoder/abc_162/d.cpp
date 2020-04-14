// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
#include <map>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL n = -1, ans = 0;
		cin >> n;
		if (n <= 0) return 0;
		string s;
		cin >> s;
		char charToIndex[256];
		const char chars[3] = { 'R', 'G', 'B' };
		vector<LL> counts[3];
		for (int i = 0; i < 3; ++i) {
			charToIndex[chars[i]] = i;
			counts[i].resize(n + 1);
			for (int j = n - 1; j >= 0; --j) {
				counts[i][j] = counts[i][j + 1] += (s[j] == chars[i]);
			}
		};
		for (LL i = 0; i < n - 2; ++i) {
			for (LL j = i + 1; j < n - 1; ++j) {
				if (s[i] != s[j]) {
					int k = 3 ^ charToIndex[s[i]] ^ charToIndex[s[j]];
					ans += counts[k][j + 1];
					if (2 * j - i < n && s[2 * j - i] == chars[k]) {
						--ans;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
