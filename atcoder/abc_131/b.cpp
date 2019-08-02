// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, l;
	cin >> n >> l;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = l + i;
	}
	int sum = accumulate(a.begin(), a.end(), 0);
	int ans, diff = 1 << 30;
	for (int i = 0; i < n; ++i) {
		int s = sum - (l + i);
		int d = abs(sum - s);
		if (d < diff) {
			diff = d;
			ans = s;
		}
	}
	cout << ans << endl;
	return 0;
}
