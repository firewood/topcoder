// D.

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n, h;
	cin >> n >> h;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	int d = a[0];
	int ans = 0, tot = 0;
	for (int i = 0; i < n; ++i) {
		if (b[i] > d) {
			++ans;
			tot += b[i];
			if (tot >= h) {
				break;
			}
		}
	}
	ans += (max(0, h - tot) + d - 1) / d;
	cout << ans << endl;
	return 0;
}
