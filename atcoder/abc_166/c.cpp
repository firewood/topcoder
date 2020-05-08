// C.

#include <iostream>
#include <sstream>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int n, m, a, b;
	cin >> n >> m;
	vector<int> h(n), good(n, 1);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		--a, --b;
		if (h[a] <= h[b]) {
			good[a] = 0;
		}
		if (h[b] <= h[a]) {
			good[b] = 0;
		}
	}
	int ans = accumulate(good.begin(), good.end(), 0);
	cout << ans << endl;
	return 0;
}
