// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

typedef long long LL;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans = accumulate(a.begin(), a.begin() + k, 0);
	cout << ans << endl;
	return 0;
}
