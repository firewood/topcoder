// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, ans = 0;
	cin >> n;
	vector<int> a(n), c(n - 1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		ans += b;
	}
	for (int i = 0; i < n - 1; ++i) {
		cin >> c[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] + 1 == a[i + 1]) {
			ans += c[a[i] - 1];
		}
	}
	cout << ans << endl;
	return 0;
}
