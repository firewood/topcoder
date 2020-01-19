// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL cnt[10][10] = {};
		int n = -1;
		cin >> n;
		if (n < 0) return 0;
		for (int i = 1; i <= n; ++i) {
			string s = to_string(i);
			int a = s[0] - '0';
			int b = s.back() - '0';
			cnt[a][b] += 1;
		}
		LL ans = 0;
		for (int i = 1; i <= 9; ++i) {
			for (int j = 1; j <= 9; ++j) {
				ans += cnt[i][j] * cnt[j][i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
