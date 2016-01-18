#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
	int N;
	cin >> N;
	int A[100000], H[100000], L[100000], f = 0, h = 0, l = 0;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		H[i] = A[i] >> 15, L[i] = A[i] & ((1 << 15) - 1);
		f |= H[i], h ^= H[i], l ^= L[i];
	}
	int lm = 1 << 30;
	for (int b = 1; b < (1 << 15); ++b) {
		int x = 0;
		for (int i = 0; i < N; ++i) {
			x ^= L[i];
		}
		lm = min(lm, x);
	}
	int ans = lm;
	if (f) {
		int hm = 1 << 30;
		for (int b = 1; b < (1 << 15); ++b) {
			int x = 0;
			for (int i = 0; i < N; ++i) {
				x ^= H[i];
			}
			hm = min(hm, x);
		}
		if (h < hm) {
			ans = (h << 15) | lm;
		} else if (l < lm) {
			ans = (hm << 15) | l;
		} else {
			ans = (hm << 15) | lm;
		}
	}
	cout << ans << endl;
	return 0;
}
