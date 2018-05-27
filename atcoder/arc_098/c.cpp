// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt[2][300002];
	int e = 0;
	for (int i = 0; i < n; ++i) {
		cnt[0][i] = e;
		e += s[i] == 'W';
	}
	e = 0;
	for (int i = n - 1; i >= 0; --i) {
		cnt[1][i] = e;
		e += s[i] == 'E';
	}
	int ans = 1 << 30;
	for (int i = 0; i < n; ++i) {
		ans = min(ans, cnt[0][i] + cnt[1][i]);
	}
	cout << ans << endl;
	return 0;
}
