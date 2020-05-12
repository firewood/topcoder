// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;

int main(int argc, char* argv[]) {
	LL n, k;
	cin >> n >> k;
	vector<int> a(n), p(n, -1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}
	int c = 0;
	for (LL t = 0; t < k; ++t) {
		c = a[c];
		if (p[c] >= 0) {
			LL f = t - p[c];
			t += max(0LL, (k - t - 1) / f) * f;
		}
		p[c] = t;
	}
	cout << (c + 1) << endl;
	return 0;
}
