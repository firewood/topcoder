// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	int ans = 0, cnt = 0, prev = 1 << 30;
	for (int i = n - 1; i >= 0; --i) {
		if (h[i] < prev) {
			cnt = 0;
		} else {
			++cnt;
		}
		ans = max(ans, cnt);
		prev = h[i];
	}
	cout << ans << endl;
	return 0;
}
