// C.

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char *argv[])
{
	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	sort(h.begin(), h.end());
	int ans = 1 << 30;
	for (int i = 0; i <= n - k; ++i) {
		ans = min(ans, h[i + k - 1] - h[i]);
	}
	cout << ans << endl;
	return 0;
}
