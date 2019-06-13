// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<int> w(n);
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
	}
	int ans = 1 << 30;
	for (int t = 1; t < 100; ++t) {
		int tot[2] = {};
		for (int i = 0; i < n; ++i) {
			tot[i <= t] += w[i];
		}
		ans = min(ans, abs(tot[0] - tot[1]));
	}
	cout << ans << endl;
	return 0;
}
