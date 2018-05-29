// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 1 << 30;
	for (int i = 0; i < n; ++i) {
		vector<int> x, y;
		for (int j = 0; j <= n; ++j) {
			if (j == n || a[j] < a[i]) {
				if (y.size() >= k) {
					sort(y.begin(), y.end());
					x.insert(x.end(), y.begin(), y.end() - k + 1);
				}
				y.clear();
			} else {
				y.push_back(a[j]);
			}
		}
		if (x.size() >= q) {
			sort(x.begin(), x.end());
			ans = min(ans, x[q - 1] - a[i]);
		}
	}
	cout << ans << endl;
}
