// C.

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int d[10];

int solve(int n, int x, int f) {
	if (f <= 0) {
		return x;
	}
	int a = (n % (f * 10)) / f;
	int b = (x % (f * 10)) / f;
	if (!d[b]) {
		return solve(n, x, f / 10);
	}
	int c = b;
	while (d[c]) {
		++c;
		while (c >= 10) {
			f *= 10;
			c = (x % (f * 10)) / f + 1;
		}
	}
	x -= x % (f * 10);
	x += c * f;
	for (int i = 0; i <= 9; ++i) {
		if (!d[i]) {
			while (f > 0) {
				f /= 10;
				x += i * f;
			}
			break;
		}
	}
	return x;
}

int main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		d[x] = 1;
	}
	int f = 1;
	for (int i = n; i >= 10; i /= 10) {
		f *= 10;
	}
	cout << solve(n, n, f) << endl;
	return 0;
}
