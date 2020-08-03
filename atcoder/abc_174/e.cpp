// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long LL;
typedef long double LD;

bool possible(int n, int k, LD x, const vector<LD>& a) {
	int cnt = 0;
	for (LD d : a) {
		cnt += (int)ceil(d / x) - 1;
	}
	return cnt <= k;
}

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, k;
		cin >> n >> k;
		if (n < 0) return 0;
		vector<LD> a(n);
		for (LL i = 0; i < n; ++i) {
			cin >> a[i];
		}
		LD left = 0.1, right = 1e10;
		for (int t = 0; t < 1000; ++t) {
			LD mid = (left + right) / 2;
			if (possible(n, k, mid, a)) {
				right = mid;
			} else {
				left = mid;
			}
		}
		cout << ceil(left) << endl;
	}
	return 0;
}
