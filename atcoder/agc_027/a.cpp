// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (x >= a[i]) {
			++ans;
			x -= a[i];
		}
	}
	if (x == a[n - 1]) {
		++ans;
	}
	cout << ans << endl;
	return 0;
}
