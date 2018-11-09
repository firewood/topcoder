// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int n, ans = 0;
	cin >> n;
	vector<int> h(n + 2), a(n + 2), b(n + 2);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
		if (i > 0 && h[i] > h[i - 1]) {
			a[i] = a[i - 1] + 1;
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		if (i < (n - 1) && h[i] > h[i + 1]) {
			b[i] = b[i + 1] + 1;
		}
		ans = max(ans, a[i] + b[i] + 1);
	}
	cout << ans << endl;
	return 0;
}
