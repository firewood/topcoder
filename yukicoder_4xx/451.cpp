#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <cstdio>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[]) {
	LL N, a[100001], b[100000], low = 1, high = 1000000000000000000;
	cin >> N;
	bool valid = true;
	for (int i = 0; i != N; ++i) {
		cin >> b[i];
		LL next_low, next_high;
		if (i % 2) {
			low = max(low, b[i] + 1);
			if (low > high) {
				valid = false;
			}
			next_low = max(1LL, low - b[i]);
			next_high = high - b[i];
		} else {
			next_low = max(1LL, b[i] - high);
			next_high = b[i] - low;
		}
		low = next_low;
		high = next_high;
		if (low > high) {
			valid = false;
		}
	}
	if (!valid) {
		cout << -1 << endl;
	} else {
		a[N] = low;
		for (int i = N - 1; i >= 0; --i) {
			if (i % 2) {
				a[i] = b[i] + a[i + 1];
			} else {
				a[i] = b[i] - a[i + 1];
			}
		}
		cout << (N + 1) << endl;
		for (int i = 0; i <= N; ++i) {
			cout << a[i] << endl;
		}
	}
	return 0;
}
