// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	cout.precision(10);
	int n, k;
	cin >> n >> k;
	vector<double> p(100001);
	double ans = 0;
	for (int i = 1; i <= n; ++i) {
		p[i] = 1.0 / n;
		if (i >= k) {
			ans += p[i];
		}
	}
	for (int i = 1; i < k; ++i) {
		if (i * 2 >= k) {
			ans += p[i] * 0.5;
		} else {
			p[i * 2] += p[i] * 0.5;
		}
	}
	cout << ans << endl;
	return 0;
}
