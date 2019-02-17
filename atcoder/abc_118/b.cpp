// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	int cnt[32] = {};
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int a;
			cin >> a;
			cnt[a] += 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		ans += cnt[i] >= n;
	}
	cout << ans << endl;
	return 0;
}
