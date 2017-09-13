// B.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n, k, l[50], ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> l[i];
	}
	sort(l, l + n);
	for (int i = n - k; i < n; ++i) {
		ans += l[i];
	}
	cout << ans << endl;
	return 0;
}
